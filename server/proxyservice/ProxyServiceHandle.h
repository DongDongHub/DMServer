#pragma once
#include "DSServiceHandle.h"
#include "ace/Task_T.h"
#include "ace/Synch_Traits.h"

class ProxyServiceHandle : public DSServiceHandle, public ACE_Svc_Handler<ACE_SOCK_Stream, ACE_MT_SYNCH>
{
public:

	//��Ҫ�Ǵ������Ϣ������������ά�������������/ɾ��proxy����Ϣ
	virtual void handle(const AMQP::Message &message) override;

	//�������Ͻ���accountid������һ��proxyserver��host
	virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE) override;

	//��дʵ�֡���Ҫ�󶨵���ͬ��reactor����
	virtual int open(void *acceptor_or_connector = 0) override;

};
