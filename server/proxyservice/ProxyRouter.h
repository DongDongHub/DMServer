#pragma once
#include "../Common/DSRouter.h"

class ProxyRouter:public DSRouter
{
public:

	//���·����Ϣ���ͻ��˵�����,��������·�ɻ���ʵ��
	virtual void route(DSServerMessage& message) override
	{
		//throw std::exception("The method or operation is not implemented.");
	}

protected:
private:
};