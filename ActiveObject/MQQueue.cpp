#include "pch.h"
#include "MQQueue.h"

MQQueue::MQQueue():capacity_(10){

}

MQQueue::~MQQueue(){

}

void MQQueue::put(Message& message){
	messages_.push_back(message);
	capacity_++;
}

Message MQQueue::get(){
	Message tmp = messages_.back();
	messages_.pop_back();
	capacity_--;
	return tmp;
}

bool MQQueue::full(){
	return  capacity_ == messages_.size();	
}

bool MQQueue::empty(){
	return messages_.empty();
}
