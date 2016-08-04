#pragma once
#include <string>

/* ��ȡ����������ļ�������������á�
*/
class DMConfig
{
public:
	static DMConfig* getInstance();

	virtual int load();

	std::string getString(std::string key);
protected:
	DMConfig();
	virtual ~DMConfig();
private:
	static DMConfig* _instance;
};

