#pragma once
#include "DMRouter.h"

#define MSG_CFG_FILE_PATH "./"

class ProxyRouter:public DMRouter
{
public:
    ProxyRouter(){};

	//���·����Ϣ���ͻ��˵�����,��������·�ɻ���ʵ��
	virtual void route(DMMessage& message) override
	{
		//throw std::exception("The method or operation is not implemented.");
	}

protected:
private:
};