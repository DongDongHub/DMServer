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
        std::map<int, std::vector<std::string>> queue_map = DMServiceMap::instance()->queue_map;
        std::vector<std::string> queue = queue_map[svr_id];
        //将message推送到rabbitmq-server，依据路由表选择或选择消息最少的队列
        //消息直接负载映射无指定cluster、node场景
        DMBrokerProxy::getInstance()->publish(exchange,queue[0],message.body,message.head.length);
    }
}

