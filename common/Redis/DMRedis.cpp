#include "hiredis/hiredis.h"
#include <ace/Log_Msg.h>
#include "DMRedis.h"

DMRedis::DMRedis():_redis_ctx(NULL)
{

}

DMRedis::~DMRedis()
{
    if (NULL != _redis_ctx)
    {
        disconnect_redis();
    }
}

bool DMRedis::init(std::string ip, int port)
{
    return conncet_redis(ip, port);
}

bool DMRedis::conncet_redis(std::string ip, int port)
{
    _redis_ctx = redisConnect(ip.c_str(), port);
    
    if (_redis_ctx == NULL || _redis_ctx->err) 
    {
        if (_redis_ctx) 
        {
            // handle error
            ACE_DEBUG((LM_ERROR,"connect redis error: %s\n", _redis_ctx->errstr));
        } 
        else 
        {
            ACE_DEBUG((LM_ERROR,"Can't allocate redis context\n"));
        }
        
        return false;
    }
    
    return true;
}

void DMRedis::disconnect_redis()
{
    redisFree(_redis_ctx);
    _redis_ctx = NULL;
}

bool DMRedis::write_redis(std::string cmd)
{
    if (NULL == redisCommand(_redis_ctx, cmd.c_str()))
    {
        ACE_DEBUG((LM_ERROR,"redis write %s failure!\n", cmd));
        return false;
    }
    return true;
}

bool DMRedis::write_redis(std::string key, std::string value)
{
    return true;
}

