#pragma once
#include "DMRouter.h"

class ProxyRouter:public DMRouter
{
public:

	//���·����Ϣ���ͻ��˵�����,��������·�ɻ���ʵ��
	virtual void route(DMMessage& message) override
	{
		//throw std::exception("The method or operation is not implemented.");
	}

protected:
private:
};