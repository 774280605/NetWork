#include "pch.h"
#include "ConcreteElement.h"
#include "Visitor.h"
#include <iostream>

void ConcreteElement::accept(Visitor* visitor){
	visitor->visit(this);
}

void ConcreteElement::show(){
	std::cout << "concreteElement()" << std::endl;
}
