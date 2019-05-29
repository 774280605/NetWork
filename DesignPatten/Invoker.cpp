#include "pch.h"
#include "Invoker.h"


Invoker::Invoker() {
}


Invoker::~Invoker() {
}

void Invoker::show() {
	command_->execute();
}
