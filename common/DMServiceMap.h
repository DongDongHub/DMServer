#pragma once

#include <map>
#include "ace/Thread_Mutex.h"

#define SERVICE_MAP_PATH "..//..//common//MsgRoute.json"

class DMServiceMap
{
public:
    static DMServiceMap* instance();
    
    DMServiceMap();
    
    //<serverid,message_max>,消息直接映射无指定cluster、node场景
    std::map<std::string, int> service_map;
    std::map<int, int> message_map;  
private: 
    void load_cfg();

	static DMServiceMap* _instance;
    static ACE_Thread_Mutex _mutex_lock;
};

