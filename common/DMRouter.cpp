#include "DMRouter.h"
#include "DMBrokerProxy.h"
#include "DMMessageParser.h"
#include <fstream>
#include "json/json.h"
#include <ace/Log_Msg.h>
#include <map>

void DMRouter::send(DMMessage& message, std::string exchange)
{
    //有路由表数据需要维护该用户路由表信息,需要维护redis内存数据
    if (0 != message.head.cluster_id && 0 != message.head.node_id)
    {
    
    }
    
    route(message, exchange);
}

void DMRouter::publish(DMMessage& message)
{
    route(message, FANOUT);
}

void DMRouter::route(DMMessage& message, std::string exchange)
{
    std::map<int, MsgRange> message_map = DMServiceMap::instance()->message_map;
    std::map<int, MsgRange>::iterator it = message_map.begin();

    int svr_id = 0;
    for (; it != message_map.end(); ++it)
    {
        MsgRange range = it->second;
        if (message.head.msg_cmd > range.msg_start &&
                message.head.msg_cmd < range.msg_end)
        {       
            svr_id = it->first;
            break;
        }
    }

    if (0 != svr_id)
    {   
        //将message推送到rabbitmq-server，依据路由表选择或选择消息最少的队列
        
        //route_assign(message, svr_id, exchange);
        
        route_distribute(message, svr_id, exchange);
        
    }
}

bool DMRouter::route_assign(DMMessage& message, int service_id, std::string exchange)
{
    DMMessageParser parser;
    //pack msg
    char *buf = new char[HEAD_CHAR_LEN + message.head.length];
    parser.pack(message,buf);
    
    return true;
}

void DMRouter::route_distribute(DMMessage& message, int service_id, std::string exchange)
{
    DMMessageParser parser;
    //pack msg
    char *buf = new char[HEAD_CHAR_LEN + message.head.length];
    parser.pack(message,buf);
    
    //消息直接负载映射无指定cluster、node场景
    std::map<int, std::vector<std::string>> queue_map = DMServiceMap::instance()->queue_map;
    std::vector<std::string> queue = queue_map[service_id];
    std::vector<std::string>::iterator it = queue.begin();
    //第一个队列作为初始化值
    std::string queueName = *it;
    int msgCount = DMBrokerProxy::getInstance()->getQueueMsgCount(queueName);

    for (; it != queue.end(); ++it)
    {
        int size = DMBrokerProxy::getInstance()->getQueueMsgCount(queueName);
        if (msgCount > size)
        {
            queueName = *it;
            msgCount = size;
        }
    }
    
    DMBrokerProxy::getInstance()->publish(exchange, queueName, buf, HEAD_CHAR_LEN + message.head.length);

    delete[] buf;
}

