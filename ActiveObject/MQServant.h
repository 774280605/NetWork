#pragma once
#include <array>

#include"Message.h"
class MQServant
{
public:
	MQServant();
	virtual ~MQServant();

	void put(const Message&msg);
	Message get();
	bool empty()const;
	bool full()const;
private:
	std::array<Message,10> messages_;
};
