#include "ProxyServiceHandle.h"
#include "DMMessageParser.h"
#include "DMBrokerProxy.h"
#include "ProxyRouter.h"
#include "ReactorPool.h"
#include "ProxySessionMgr.h"
#include <ace/Log_Msg.h>

void ProxyServiceHandle::handle(const AMQP::Message &message)
{
	//server message
	ACE_DEBUG((LM_INFO,"proxy recevie msg,route to app or others\n"));
}

int ProxyServiceHandle::handle_input(ACE_HANDLE fd /*= ACE_INVALID_HANDLE*/)
{
	ACE_DEBUG((LM_INFO,"app data, route to server!\n"));
	DMMessage client_msg;

	if (!recv_client_data(client_msg))
	{
		return -1;
	}

	switch (client_msg.head.flag & MSG_MASK)
	{
	case LOGIN_MSG:
		{
			user_connect(fd);  
			DMMessage server_msg;
            ACE_DEBUG((LM_INFO,"RECIVE LOGIN_MSG!\n"));

			break;
		}
	case HEARTBEAT_MSG:
		{
			break;
		}
	case SERVICE_MSG:
		{
			break;
		}
	case NOTIFY_MSG:
		{
			break;
		}
	case MAINT_MSG:
		{
			break;
		}
	}

	return 0;
}
	
bool ProxyServiceHandle::recv_client_data(DMMessage &msg)
{
	char head[DMMessageParser::HEAD_CHAR_LEN] = {0};
	if (peer().recv(head,DMMessageParser::HEAD_CHAR_LEN) < 1)
    {
        user_disconnect(peer().get_handle());
        return false;
    }   
	
	DMMessageParser parser;
	DMMessageHead head_info;
	//parse head
	head_info = parser.parse(head);

    //some message maybe have no message body
    do
    {
    	if ( head_info.length <= 0 )
    	{
    		break;
    	}

    	//recive body
    	msg.body = new char[head_info.length];
    	memset(msg.body,0,head_info.length);
    	peer().recv(msg.body,head_info.length);
        
    }while(false);

	msg.head = head_info;

	return true;
}

void ProxyServiceHandle::user_connect(ACE_HANDLE fd)
{
    ProxySessionMgr::instance()->add_session(fd, new ProxySession(this));//fd作为sessionid
}

void ProxyServiceHandle::user_disconnect(ACE_HANDLE fd)
{
    ProxySessionMgr::instance()->del_session(fd);//fd作为sessionid
    handle_close();
}

int ProxyServiceHandle::open(void *acceptor_or_connector /*= 0*/)
{
	ACE_Reactor *pReactor = Reactor_Pool::instance()->pull();
	if ( -1 == get_handle() || nullptr == pReactor)
	{
		return -1;
	}

	if ( -1 == pReactor->register_handler(this,ACE_Event_Handler::READ_MASK /*| ACE_Event_Handler::WRITE_MASK*/))
	{
		ACE_DEBUG((LM_INFO,"register_handler failure,all reactor is full!\n"));
		return -1;
	}

	return 0;
}

