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
        //����msg_cmd��ȡservice_id
        int range = it->second;
        if (message.head.msg_cmd > range)
        {
            break;
        }
    }
    //��message���͵�rabbitmq-server
    //broker->publish
}

