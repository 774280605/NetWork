#pragma once
#include "Observer.h"
class ConcreteObserver:public Observer
{
public:
	ConcreteObserver(Subject*subject);
	virtual ~ConcreteObserver();

	void update() override;

private:
	Subject*subject_;
};
