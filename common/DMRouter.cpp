#include "DMRouter.h"
#include "DMBrokerProxy.h"
#include "DMMessageParser.h"
#include <fstream>
#include "json/json.h"
#include <map>

void DMRouter::route(DMMessage& message)
{
    std::map<int, int> message_map = DMServiceMap::instance()->message_map;
    std::map<int, int>::iterator it = message_map.begin();
    for (; it != message_map.end(); ++it)
    {
        //依据msg_cmd获取service_id
        int range = it->second;
        if (message.head.msg_cmd > range)
        {
            break;
        }
    }
    //将message推送到rabbitmq-server
    //broker->publish
}

