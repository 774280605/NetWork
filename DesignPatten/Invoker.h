#pragma once
#include "Command.h"

class Invoker
{
public:
	Invoker();

	explicit Invoker(Command* command)
		: command_(command) {
	}

	virtual ~Invoker();

	void show();

private:
	Command*command_;
};

