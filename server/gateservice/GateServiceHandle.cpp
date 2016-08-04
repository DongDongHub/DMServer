#include <ace/Reactor.h>
#include <ace/Log_Msg.h>
#include "GateServiceHandle.h"
#include "ProxyMapManager.h"
#include "DMServerMessageParser.h"
#include "DMClientMessageParser.h"
#include "GateServiceMsg.pb.h"
#include "GateService.h"
#include <string>

GateServiceHandle::GateServiceHandle()
{

}

GateServiceHandle::~GateServiceHandle()
{

}

void GateServiceHandle::handle(const AMQP::Message &message)
{
	ACE_DEBUG((LM_INFO,"recived msg from server!\n"));
	DMServerMessageParser parser;

	//parse message
	DMServerMessage req_msg;
	if (!parser.parse(req_msg,message))
	{
		ACE_DEBUG((LM_INFO,"parse AMQP::Message error!\n"));
		return;
	}
		
	//pb decode
	PBServerMsg msg_pb;
	//std::string pb_data(req_msg.body,req_msg.head.len);

	if (!msg_pb.ParseFromString(req_msg.body))
	{
		ACE_DEBUG((LM_INFO,"ParseFromString error!\n"));
		return;
	}

	std::string key = msg_pb.key();
	std::string proxy = msg_pb.proxy();
	
	switch (req_msg.head.type)
	{
	case ADD_PROXY_MSG:
		{
			//���proxy����
			ProxyMapManager::getInstance()->update(key.at(0),proxy);
			break;
		}
	case RMV_PROXY_MSG:
		{
			//����proxy���Զ����¸��¹���
			ProxyMapManager::getInstance()->remove(key.at(0));
		}
	case STOP_SERVER:
		{
			ACE_Reactor::instance()->end_reactor_event_loop();
		}
		//ͣ��
	default:
		break;
	}
}

int GateServiceHandle::handle_input(ACE_HANDLE fd /*= ACE_INVALID_HANDLE*/)
{
	//recevie msg
	DMClientMessage req_msg;

	if (!recv_client_data(req_msg))
	{
		return -1;
	}

	//pb decode
	PBClientMsg msg_pb;
	std::string pb_data(req_msg.body,req_msg.head.len);

	if(!msg_pb.ParseFromString(pb_data))
	{
		ACE_DEBUG((LM_INFO,"ParseFromString error!\n"));
		return false;
	}

	//get proxy
	std::string accountid = msg_pb.accountid();
	std::string proxy = ProxyMapManager::getInstance()->hash(accountid.at(accountid.length() - 1)); //�������һλhash

	//response app
	DMClientMessage resp_msg;
	resp_msg.head.id = req_msg.head.id;
	resp_msg.head.svrid = req_msg.head.svrid;
	resp_msg.head.reserved = req_msg.head.reserved;
	resp_msg.head.type = req_msg.head.type;

	//pb encode
	std::string strBody;
	msg_pb.set_proxy(proxy.c_str(),proxy.length());

	if (!msg_pb.SerializeToString(&strBody))
	{
		return -1;
	}

	resp_msg.head.len = msg_pb.ByteSize();
	resp_msg.body = new char[msg_pb.ByteSize()];

	memcpy(resp_msg.body,strBody.c_str(),strBody.length());

	//send
	send_client_data(resp_msg);

	//close
	return -1;
}

bool GateServiceHandle::recv_client_data(DMClientMessage &msg)
{
	char head[DMClientMessageParser::HEAD_CHAR_LEN] = {0};
	peer().recv(head,DMClientMessageParser::HEAD_CHAR_LEN);
	
	DMClientMessageParser parser;
	DMClientMessageHead head_info;
	//parse head
	head_info = parser.parseHead(head);

	if ( head_info.len <= 0 )
	{
		return false;
	}

	//recive body
	msg.body = new char[head_info.len];
	memset(msg.body,0,head_info.len);
	peer().recv(msg.body,head_info.len);

	msg.head = head_info;

	return true;
}

void GateServiceHandle::send_client_data(DMClientMessage &msg)
{
	DMClientMessageParser parser;
	char *buf = new char[DMClientMessageParser::HEAD_CHAR_LEN + msg.head.len];

	//pack msg
	parser.pack(msg,buf);

	//send
	peer().send_n(buf,DMClientMessageParser::HEAD_CHAR_LEN + msg.head.len);

	delete[] buf;
}
