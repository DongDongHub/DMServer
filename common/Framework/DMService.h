#pragma once
#include "amqpcpp/include/message.h"
#include "DMServiceHandle.h"
#include "DMRouter.h"

//调整类成员结构，可单独运行，业务接入采取策略模式，降低代码耦合，DMServiceHandle为接入对象
//控制类应该处于网络层和应用层之间，需要封装底层IO和dispatch，route应该在更底层，放在dispatch下一层
//dispatch除了包含route，还需要包含一个消息工厂。这个消息工厂由业务层提供，包括了消息定义注册和消息头处理和proto规则。对业务直接提供可靠数据
//由此，业务上只需要提供业务handle策略和消息工厂即可，这两个都必须提供一套完整的底层基本功能类，上层只需要进行基本的注册操作即可
//数据库和其他第三方接口单独存在，完全独立通用，以组合形式引用到业务上
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
