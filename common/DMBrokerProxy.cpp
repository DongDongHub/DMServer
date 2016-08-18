#include "DMBrokerProxy.h"
#include "ace/Reactor.h"
#include "DMService.h"
#include <ace/Log_Msg.h>
#include <DMServiceMap.h>
#include <map>
extern DMService* GetService();

DMBrokerProxy* DMBrokerProxy::_instance = NULL;

int DMBrokerProxy::init(std::string host,int port, std::string username, std::string userpasswd, int svrid)
{
	// create an instance of your own tcp handler
	_handle = new DMBrokerMessageHandle();

	// address of the server
	AMQP::Address address(host, port,AMQP::Login(username,userpasswd),"/");

	// create a AMQP connection object
	_connection = new AMQP::TcpConnection(_handle, address);

	// and create a channel
	_channel = new AMQP::TcpChannel(_connection);

	auto receiveMessageCallback = [=](const AMQP::Message &message,
		uint64_t deliveryTag,
		bool redelivered)
	{
		GetService()->receive(message);
		//_channel->ack(deliveryTag);
	};

	AMQP::QueueCallback callback =
		[=](const std::string &name, int msgcount, int consumercount)
	{
		_channel->bindQueue("my_service", name, name);
		_channel->bindQueue("my_service", name, "monitor");
		_channel->bindQueue("my_service", name, "heartbeat");

		_channel->consume(name, AMQP::noack).onReceived(receiveMessageCallback);
	};

	AMQP::SuccessCallback success = [svrid, this, callback]()
	{
	    std::map<std::string, int> svr_map = DMServiceMap::instance()->service_map;
        std::map<std::string, int>::iterator svr_it = svr_map.begin();
        for (; svr_it != svr_map.end(); ++svr_it)
        {
            //待优化，修改配置。一个service绑定多个queue
            _channel->declareQueue(svr_it->first, AMQP::durable).onSuccess(callback);
        }        
	};

	// use the channel object to call the AMQP method you like
	_channel->declareExchange("my_service", AMQP::fanout).onSuccess(success);

	return 0;
}

void DMBrokerProxy::publish(const std::string &exchange, const std::string &routingKey, const char *message, size_t size)
{
	_channel->publish(exchange, routingKey, message, size);
}

void DMBrokerProxy::runEvents()
{
	ACE_Reactor::instance()->run_event_loop();
}

void DMBrokerProxy::destroy()
{
	if (_handle)
	{
		delete _handle;
		_handle = nullptr;
	}

	if (_connection)
	{
		delete _connection;
		_connection = nullptr;
	}

	if (_channel)
	{
		delete _channel;
		_channel = nullptr;
	}

	if (_instance)
	{
		delete _instance;
		_instance = nullptr;
	}
}

DMBrokerProxy::~DMBrokerProxy()
{
	destroy();
}
