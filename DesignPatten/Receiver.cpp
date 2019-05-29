#include "pch.h"
#include "Receiver.h"
#include <iostream>


Receiver::Receiver() {
}


Receiver::~Receiver() {
}

void Receiver::action() {
	std::cout << "Receiver::action()" << std::endl;
}
