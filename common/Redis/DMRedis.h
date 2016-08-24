#pragma once
#include "hiredis/hiredis.h"

#define REDIS_CFG_FILE "..//..//common//Redis//config.json"
//各个进程单独实例化，多个实例同时连接redis
//Redis所有API均使用同步操作
//表数据采用hash结构存储   key为表名  domain为主键  value为字典形式行值{"":"","":""}
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

    bool write_redis_cmd(std::string cmd);

    std::string read_redis_cmd(std::string cmd);

    bool write_redis_string(std::string keys, std::string value);

    std::string read_redis_string(std::string keys);

    bool write_redis_hash(std::string keys, std::string domain, std::string value);

    std::string read_redis_hash(std::string keys, std::string domain);

    bool ping_redis();
    
private:
    bool load_redis_config();
    
    void init();
     
    bool conncet_redis(std::string ip, int port);

    void disconnect_redis();

private:
    redisContext *_redis_ctx;
    redis_cfg _redis_cfg;
};

