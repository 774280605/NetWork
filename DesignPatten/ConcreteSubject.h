#pragma once
#include "Subject.h"
#include <vector>

class ConcreteSubject:public Subject
{
public:
	ConcreteSubject();
	virtual~ConcreteSubject();

	void attach(Observer* observer) override;
	void detach(Observer* observer) override;
	void notify() override;

	int statue() override;
private:
	std::vector<Observer*> observers_;
	int myStatue;
};
