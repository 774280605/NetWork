#include "pch.h"
#include "ConcreteSubject.h"
#include "Observer.h"
ConcreteSubject::ConcreteSubject():myStatue(5){
}

ConcreteSubject::~ConcreteSubject(){
}

void ConcreteSubject::attach(Observer* observer){
	observers_.push_back(observer);
}

void ConcreteSubject::detach(Observer* observer){
	
}

void ConcreteSubject::notify(){
	for (auto observer : observers_){
		observer->update();
	}
}

int ConcreteSubject::statue(){
	return myStatue;
}
