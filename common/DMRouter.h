#pragma once
#include "DMMessage.h"
#include "DMServiceMap.h"
//��Ϣ·����������������Ϣ·�ɵ���Ϣ������
//������ͨ����ֱ��ʹ�þͿɡ� ����proxyServer����Ҫ���أ����·�ɵ��ͻ��˵�������

class DMRouter
{
public:
    
	virtual void route(DMMessage& message);
    
protected:
            
private:

};
