#pragma once
#include "DMServiceHandle.h"
#include "ace/Task_T.h"
#include "ace/Synch_Traits.h"
#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"
#include "ProxyRouter.h"
#include "DMMessage.h"

class ProxyServiceHandle : public DMServiceHandle, public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
public:
	//��Ҫ�Ǵ������Ϣ������������ά�������������/ɾ��proxy����Ϣ
	virtual void handle(const AMQP::Message &message) override;

	//�������Ͻ���accountid������һ��proxyserver��host
	virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE) override;

	bool recv_client_data(DMMessage &msg);

    void user_connect(ACE_HANDLE fd);

    void user_disconnect(ACE_HANDLE fd);

	//��дʵ�֡���Ҫ�󶨵���ͬ��reactor����
	virtual int open(void *acceptor_or_connector = 0) override;

private:
};
