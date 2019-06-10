#pragma once
#include <vector>
#include "Message.h"

class MQQueue
{
public:
	MQQueue();
	virtual ~MQQueue();

	void put(Message&message);
	Message get();

	bool full();
	bool empty();

private:
	int capacity_;
	std::vector<Message> messages_;
};
