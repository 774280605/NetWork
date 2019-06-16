#include "pch.h"
#include "ConcreteVisitor.h"
#include "Element.h"
void ConcreteVisitor::visit(Element* element){
	element->show();
}
