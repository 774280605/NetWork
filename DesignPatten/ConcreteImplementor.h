#pragma once
#include "Implementor.h"

class ConcreteImplementor:public Implementor{
public:
	ConcreteImplementor();
	virtual ~ConcreteImplementor();


	void show() override;
};
