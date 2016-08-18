#include "DMServiceMap.h"
#include <fstream>
#include "json/json.h"
#include <ace/Log_Msg.h>

DMServiceMap* DMServiceMap::_instance = nullptr;
ACE_Thread_Mutex DMServiceMap::_mutex_lock;

DMServiceMap* DMServiceMap::instance()
{
	_mutex_lock.acquire();
	if (nullptr == _instance)
	{
		_instance = new DMServiceMap();
	}
	_mutex_lock.release();
	return _instance;
}

DMServiceMap::DMServiceMap()
{
    load_cfg();
}

void DMServiceMap::load_cfg()
{
    std::ifstream cfg_file;
    cfg_file.open(SERVICE_MAP_PATH, std::ios::binary);

    if (!cfg_file.is_open())
    {   
        ACE_DEBUG((LM_INFO,"open MsgRoute.json config failure!\n"));
        return;
    }

    Json::Reader Reader;
    Json::Value Root;

    if (Reader.parse(cfg_file,Root))
    {
        Json::Value service_id = Root["service_id"];
        Json::Value::Members members = service_id.getMemberNames();
        Json::Value::Members::iterator it = members.begin();
        for (; it != members.end(); ++it)
        {
            std::string service_name = *it;
            int svr_id = service_id[service_name].asInt();
            service_map.insert(std::make_pair(service_name,svr_id));
        }

        Json::Value message_route = Root["message_route"];
        std::map<std::string, int>::iterator svr_it = service_map.begin();
        for (; svr_it != service_map.end(); ++svr_it)
        {
            int svr_id = svr_it->second;
            int msg_range = message_route[svr_it->first].asInt();
            message_map.insert(std::make_pair(svr_id,msg_range));
        }
    }
}

