#pragma once
#include "DMMessage.h"
//��Ϣ·����������������Ϣ·�ɵ���Ϣ������
//������ͨ����ֱ��ʹ�þͿɡ� ����proxyServer����Ҫ���أ����·�ɵ��ͻ��˵�������
enum CLIENT_MSG_TYPE
{
	CLIENT_REQUEST_MSG   = 0x000,
	CLIENT_RESPONS_MSG   = 0x400,

	CLIENT_LOGIN_MSG     = 0x200,
	CLIENT_HEARTBEAT_MSG = 0x100,
	CLIENT_SERVICE_MSG	 = 0x080,
	CLIENT_NOTIFY_MSG    = 0x040,
	CLIENT_MAINT_MSG     = 0x020,

	CLIENT_MSG_MASK      = 0x3FF,
};

class DMRouter
{
public:
	virtual void route(DMServerMessage& message);
protected:
private:
};