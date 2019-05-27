#pragma once
#include "Abstraction.h"
#include "Implementor.h"
class RefineAbstraction:public Abstraction {
public:

	RefineAbstraction(Implementor*implementor);
	virtual ~RefineAbstraction()=default;


	void show() override;

private:
	Implementor* implementor_;
};
