#include "pch.h"
#include "ConcreteImplementor.h"
#include <iostream>

ConcreteImplementor::ConcreteImplementor() {
}

ConcreteImplementor::~ConcreteImplementor() {
}

void ConcreteImplementor::show() {
	std::cout << "ConcreteImplementor::show()" << std::endl;;
}
