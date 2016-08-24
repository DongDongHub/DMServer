#include "json/json.h"
#include <fstream>
#include <ace/Log_Msg.h>
#include "DMMySQL.h"

DMMySQL::DMMySQL():_conn(false)
{
    init();
}

DMMySQL::~DMMySQL()
{
    disconnect_mysql();
}

bool DMMySQL::load_mysql_config()
{
    std::ifstream cfg_file;
    cfg_file.open(MYSQL_CFG_FILE, std::ios::binary);

    if (!cfg_file.is_open())
    { 
        return 0;
    }

    Json::Reader Reader;
    Json::Value Root;

    if (Reader.parse(cfg_file,Root))
    {
        _mysql_cfg.ip = Root["mysql_ip"].asString();
        _mysql_cfg.user = Root["mysql_user"].asString();
        _mysql_cfg.passwd = Root["mysql_passwd"].asString();
        _mysql_cfg.database_name = Root["database_name"].asString();
    }
    else
    {
        ACE_DEBUG((LM_ERROR,"parse mysql config file failure!\n"));    
        return false;
    }
    
    return true;
}

void DMMySQL::init()
{
    if (load_mysql_config())
    {
        conncet_mysql(_mysql_cfg.ip, _mysql_cfg.user, _mysql_cfg.passwd);
    }
}

bool DMMySQL::conncet_mysql(std::string ip, std::string user, std::string passwd)
{   
    return true;
}

void DMMySQL::disconnect_mysql()
{
   
}

bool DMMySQL::write_mysql_cmd(std::string cmd)
{
   
    return true;
}

std::string DMMySQL::read_mysql_cmd(std::string cmd)
{
    std::string reslut;
    return reslut;
}

