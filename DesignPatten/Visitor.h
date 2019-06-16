#pragma once
class Element;
class Visitor {
public:
	Visitor();
	virtual ~Visitor();

	virtual  void visit(Element*element) = 0;
};

