#pragma once

//各个进程单独实例化，多个实例同时连接redis
//Redis所有API均使用同步操作
class DMRedis
{
public:
    DMRedis();
    ~DMRedis();
    bool init(std::string ip, int port);

    bool write_redis(std::string cmd);

    bool write_redis(std::string key, std::string value);
    
private:
    bool conncet_redis(std::string ip, int port);

    void disconnect_redis();

private:
    redisContext *_redis_ctx;
};
