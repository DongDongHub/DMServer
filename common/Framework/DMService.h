#pragma once
#include "amqpcpp/include/message.h"
#include "DMServiceHandle.h"
#include "DMRouter.h"

//�������Ա�ṹ���ɵ������У�ҵ������ȡ����ģʽ�����ʹ�����ϣ�DMServiceHandleΪ�������
//������Ӧ�ô���������Ӧ�ò�֮�䣬��Ҫ��װ�ײ�IO��dispatch��routeӦ���ڸ��ײ㣬����dispatch��һ��
//dispatch���˰���route������Ҫ����һ����Ϣ�����������Ϣ������ҵ����ṩ����������Ϣ����ע�����Ϣͷ�����proto���򡣶�ҵ��ֱ���ṩ�ɿ�����
//�ɴˣ�ҵ����ֻ��Ҫ�ṩҵ��handle���Ժ���Ϣ�������ɣ��������������ṩһ�������ĵײ���������࣬�ϲ�ֻ��Ҫ���л�����ע���������
//���ݿ�������������ӿڵ������ڣ���ȫ����ͨ�ã��������ʽ���õ�ҵ����
class DMService
{
public:
	virtual int init()=0;

    virtual void dispatch(DMMessage& message) { _router->send(message); };
    
    virtual void publish(DMMessage& message) { _router->publish(message); };

    virtual void receive(const AMQP::Message &message);
	
	virtual void stop(int reason) {};

	void setHandle(DMServiceHandle* handle) { _handle = handle; };
	void setRouter(DMRouter* router) { _router = router; };
protected:
	virtual void onStart(int reason) {};

	DMServiceHandle* _handle;
	DMRouter* _router;
};
