#pragma once
#include "mysql++.h"

#define MYSQL_CFG_FILE "..//..//common//MySQL//config.json"


typedef struct mysql_config
{
    std::string ip;
    std::string user;
    std::string passwd;
    std::string database_name;
}mysql_cfg;

class DMMySQL
{
public:
    DMMySQL();
    ~DMMySQL();

    bool write_mysql_cmd(std::string cmd);

    std::string read_mysql_cmd(std::string cmd);
    
private:
    bool load_mysql_config();
    
    void init();
     
    bool conncet_mysql(std::string ip, std::string user, std::string passwd);

    void disconnect_mysql();

private:
    mysql_cfg _mysql_cfg;
    mysqlpp::Connection _conn;
};

