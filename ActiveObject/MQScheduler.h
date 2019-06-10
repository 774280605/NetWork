#pragma once
#include "MethodRequest.h"
#include "Activation_list.h"
#include "MQQueue.h"

class MQScheduler
{
public:
	MQScheduler();
	virtual ~MQScheduler();
	void put(Message&msg);
	Message get();
	virtual void dispatch();

private:
	Activation_list activationList_;
	MQQueue queue_;
	static void* svcRun(void*arg);
};
