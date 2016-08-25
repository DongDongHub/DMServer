#include "json/json.h"
#include <fstream>
#include <ace/Log_Msg.h>
#include "DMMySQL.h"

DMMySQL::DMMySQL()
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
        _mysql_cfg.port = Root["mysql_port"].asInt();
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
        conncet_mysql();
    }
}

bool DMMySQL::conncet_mysql()
{ 
    if (!_conn.connect(_mysql_cfg.database_name.c_str(), _mysql_cfg.ip.c_str(),
        _mysql_cfg.user.c_str(), _mysql_cfg.passwd.c_str(), _mysql_cfg.port))
    {
        ACE_DEBUG((LM_ERROR,"connect MySQL database failure!\n"));    
        return false;
    }
    mysql_table a;
    read_mysql("tbl_route",a);

    return true;
}

void DMMySQL::show_databases_info(int flag, std::vector<std::string>& databases)
{
    std::string opration;    
   
    switch (flag)
    {
    case SHOW_VERISON:
        {
            std::string version_info = _conn.client_version();
            databases.push_back(version_info);
            return;
        }
    case SHOW_DATABASES:
        {
            opration = "show databases";
            break; 
        }
    case SHOW_TABLES:
        {
            
            opration = "show tables";
            break; 
        }
    default:
        {
            return;
        }
    }

    mysqlpp::Query query = _conn.query(opration);
    if (mysqlpp::StoreQueryResult res = query.store())
    {           
        mysqlpp::StoreQueryResult::iterator rit;	
        for (rit = res.begin(); rit != res.end(); ++rit) 
        {
            databases.push_back((*rit)[0].c_str());
        }    
    }
}

void DMMySQL::get_table_desc(std::string table_name, mysql_table_info& tbl_info)
{
    std::string opration = "describe " + table_name;    
    mysqlpp::Query query = _conn.query(opration);
    mysqlpp::StoreQueryResult res = query.store();

    int field_num = res.size();
    for (int i = 0; i < field_num; ++i)
    {
        mysql_field_info field_i;
        
        field_i.Field   = res[i]["field"].c_str();
        field_i.Type    = res[i]["type"].c_str();
        field_i.Null    = res[i]["null"].c_str();
        field_i.Key     = res[i]["key"].c_str();
        field_i.Default = res[i]["default"].c_str();
        field_i.Extra   = res[i]["extra"].c_str();
        
        tbl_info.push_back(field_i);
    }
}

void DMMySQL::disconnect_mysql()
{
    _conn.disconnect();
}

bool DMMySQL::write_mysql(std::string sql)
{
   
    return true;
}

bool DMMySQL::read_mysql(std::string table_name, mysql_table& table_data)
{
    std::string opration = "select * from " + table_name;    
    mysqlpp::Query query = _conn.query(opration);
    mysqlpp::StoreQueryResult res = query.store();
    
    int field_num = res.num_fields();
    if (!field_num)
    {
        return false;
    }

    for (int i = 0; i < field_num; ++i)
    {
        ACE_DEBUG((LM_INFO,"%s\n",res.field_name(i).c_str()));
    }
    /*
    std::string field_name = res.field_name(i);
            mysql_field field_data;
            while (mysqlpp::Row row = res.fetch_row()) 
            {
                        
            }*/

    return true;
}

bool DMMySQL::read_mysql(std::string table_name, std::string field_name)
{
    return true;
}

bool DMMySQL::read_mysql(std::string table_name, std::string field_name, std::string filter)
{
    return true;
}

