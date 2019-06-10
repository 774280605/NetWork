#include "pch.h"
#include "Activation_list.h"

Activation_list::Activation_list():capacity_(10){
}

Activation_list::~Activation_list(){
}

Activation_list::Activation_list(size_t high_water_mark){
}

void Activation_list::insert(MethodRequest* methodRequest){
	std::unique_lock<std::mutex> lock(mutex_);
	while (requests_.size()==10){
		condition_.wait(lock);
	}
	requests_.push_back(methodRequest);
	
}

void Activation_list::remove(MethodRequest* methodRequest){
	std::unique_lock<std::mutex> lock(mutex_);
	for (auto it = requests_.begin();it!=requests_.end();++it){
		if (*it == methodRequest){
			requests_.erase(it);
			break;
		}
	}

	condition_.notify_one();
}

MethodRequest* Activation_list::pop(){

	if (true){
		
	}
	return nullptr;
}
