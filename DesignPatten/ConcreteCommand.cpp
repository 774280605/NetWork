#include "pch.h"
#include "ConcreteCommand.h"


ConcreteCommand::ConcreteCommand(Receiver*receiver):receiver_(receiver) {
	
}


ConcreteCommand::~ConcreteCommand() {
}

void ConcreteCommand::execute() {
	receiver_->action();
}
