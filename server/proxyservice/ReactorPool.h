#pragma once
#include "ace/Reactor.h"

class ReactorPool
{
public:
	static ReactorPool* getInstance();

	//ȡ��һ�����õ�reactor�� һ��reactor���ƹ���1000��handle
	ACE_Reactor* pull();
protected:
	//��ʼ���̶�������reactor
	ACE_Reactor** _pool;
private:
};