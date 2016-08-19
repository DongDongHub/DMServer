#include "DMRouter.h"
#include "DMBrokerProxy.h"
#include "DMMessageParser.h"
#include <fstream>
#include "json/json.h"
#include <ace/Log_Msg.h>
#include <map>

void DMRouter::send(DMMessage& message, std::string exchange)
{
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
        //����msg_cmd��ȡservice_id,��Ϣֱ��ӳ����ָ��cluster��node����
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
        //��message���͵�rabbitmq-server
        DMBrokerProxy::getInstance()->publish(exchange,"100",message.body,message.head.length);
    }
}

