#pragma once
#include "Visitor.h"
class ConcreteVisitor:public Visitor
{
public:
	ConcreteVisitor()=default;
	virtual ~ConcreteVisitor()=default;


	void visit(Element* element) override;
};
