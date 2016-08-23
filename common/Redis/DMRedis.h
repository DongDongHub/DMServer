#pragma once

//�������̵���ʵ���������ʵ��ͬʱ����redis
//Redis����API��ʹ��ͬ������
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
