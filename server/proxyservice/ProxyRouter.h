#pragma once
#include "DMRouter.h"

class ProxyRouter:public DMRouter
{
public:
	//���·����Ϣ���ͻ��˵�����,��������·�ɻ���ʵ��
	virtual void route(DMMessage& message, std::string exchange) override
	{
		//throw std::exception("The method or operation is not implemented.");
		DMRouter::route(message, exchange);
	}

protected:
private:
};