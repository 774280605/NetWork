#include "pch.h"
#include "MQScheduler.h"

MQScheduler::MQScheduler(){
	std::thread spawn(svcRun,this);
}

MQScheduler::~MQScheduler(){
}

void MQScheduler::put(Message& msg){



}

Message MQScheduler::get(){
	return {};
	}



void MQScheduler::dispatch(){


}

void* MQScheduler::svcRun(void* arg){

	MQScheduler*scheduler = static_cast<MQScheduler*>(arg);
	scheduler->dispatch();

	return nullptr;
}
