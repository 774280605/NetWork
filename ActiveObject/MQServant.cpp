#include "pch.h"
#include "MQServant.h"
#include "Message.h"
MQServant::MQServant(){

}

MQServant::~MQServant(){

}

void MQServant::put(const Message& msg){
	messages_.fill(msg);
}

Message MQServant::get(){
	return messages_.front();
}

bool MQServant::empty() const{

	return messages_.empty();
}

bool MQServant::full() const{
	return messages_.size()==messages_.max_size();
}
