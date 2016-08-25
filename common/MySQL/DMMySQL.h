#pragma once
#include "mysql++.h"

#define MYSQL_CFG_FILE "..//..//common//MySQL//config.json"


typedef struct mysql_config
{
    std::string ip;
    int port;
    std::string user;
    std::string passwd;
    std::string database_name;
}mysql_cfg;

typedef struct mysql_field_information
{
    std::string Field;
    std::string Type;
    std::string Null;
    std::string Key;
    std::string Default;
    std::string Extra;
}mysql_field_info;

typedef std::vector<mysql_field_info> mysql_table_info;

typedef struct mysql_field_data
{
    //数字类型
    int INTEGER;
    long long BIGINT;
    float FLOAT;
    double DOUBLE;
    //时间戳类型
    long long TIMESTAMP;
    //字符类型
    char CHAR;
    std::string VARCHAR;
}mysql_field;

typedef std::map<std::string, std::vector<mysql_field>> mysql_table; //字段，值

enum mysql_database_info
{
    SHOW_VERISON,
    SHOW_DATABASES,
    SHOW_TABLES
};

class DMMySQL
{
public:
    DMMySQL();
    ~DMMySQL();

    void show_databases_info(int flag, std::vector<std::string>& databases);

    void get_table_desc(std::string table_name, mysql_table_info& table_info);

    bool write_mysql(std::string sql);

    bool read_mysql(std::string table_name, mysql_table& table_data);

    bool read_mysql(std::string table_name, std::string field_name);

    bool read_mysql(std::string table_name, std::string field_name, std::string filter);
    
private:
    bool load_mysql_config();
    
    void init();
     
    bool conncet_mysql();

    void disconnect_mysql();

private:
    mysql_cfg _mysql_cfg;
    mysqlpp::Connection _conn;
};

