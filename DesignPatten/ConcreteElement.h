#pragma once
#include "Element.h"
class ConcreteElement:public Element
{
public:
	ConcreteElement()=default;
	virtual ~ConcreteElement()=default;

	void accept(Visitor* visitor) override;

	void show() override;
};
