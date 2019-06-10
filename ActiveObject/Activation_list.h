#pragma once
#include "MethodRequest.h"
#include <mutex>
#include <array>
#include "MQQueue.h"

class Activation_list
{
public:
	Activation_list();
	virtual ~Activation_list();
	enum {INFINITE=-1,};

	Activation_list(size_t high_water_mark);

	void insert(MethodRequest*methodRequest);

	void remove(MethodRequest*methodRequest);

	MethodRequest* pop();


private:
	
	std::mutex mutex_;
	std::condition_variable condition_;

	std::vector<MethodRequest*> requests_;
	int capacity_;
};
