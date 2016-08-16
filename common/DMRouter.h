#pragma once
#include "DMMessage.h"
//��Ϣ·����������������Ϣ·�ɵ���Ϣ������
//������ͨ����ֱ��ʹ�þͿɡ� ����proxyServer����Ҫ���أ����·�ɵ��ͻ��˵�������
enum CLIENT_MSG_TYPE
{
	CLIENT_REQUEST_MSG   = 0x01,
	CLIENT_RESPONS_MSG   = 0x02,

	CLIENT_LOGIN_MSG     = 0x04,
	CLIENT_HEARTBEAT_MSG = 0x08,
	CLIENT_SERVICE_MSG	 = 0x10,
	CLIENT_NOTIFY_MSG    = 0x20,
	CLIENT_MAINT_MSG     = 0x40,

	CLIENT_MSG_MASK      = 0xFF,
};

class DMRouter
{
public:
	virtual void route(DMMessage& message);
protected:
private:
};