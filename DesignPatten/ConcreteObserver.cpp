#include "pch.h"
#include "ConcreteObserver.h"

#include "ConcreteSubject.h"
#include <iostream>

ConcreteObserver::ConcreteObserver(Subject* subject){
	subject_ = subject;
}

ConcreteObserver::~ConcreteObserver(){

}

void ConcreteObserver::update(){
	int statue = subject_->statue();
	std::cout <<"hahah:"<< statue << std::endl;
}
