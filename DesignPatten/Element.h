#pragma once
class Visitor;
class Element
{
public:
	Element() = default;
	virtual ~Element() = default;

	virtual void accept(Visitor*visitor) = 0;
	virtual void show()=0;
};
