#pragma once
#include "Command.h"
#include "Receiver.h"
class ConcreteCommand :
	public Command
{
public:
	ConcreteCommand(Receiver*receiver);
	virtual ~ConcreteCommand();

	virtual void execute() override;


private:
	Receiver*receiver_;
};

