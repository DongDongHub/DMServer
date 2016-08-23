#pragma once
#include "hiredis/hiredis.h"

#define REDIS_CFG_FILE "..//..//common//Redis//config.json"
//�������̵���ʵ���������ʵ��ͬʱ����redis
//Redis����API��ʹ��ͬ������
typedef struct redis_config
{
    std::string ip;
    int port;
}redis_cfg;

class DMRedis
{
public:
    DMRedis();
    ~DMRedis();

    bool write_redis(std::string cmd);

    bool write_redis(std::string key, std::string value);
    
private:
    bool load_redis_config();
    
    void init();
     
    bool conncet_redis(std::string ip, int port);

    void disconnect_redis();

private:
    redisContext *_redis_ctx;
    redis_cfg _redis_cfg;
};
