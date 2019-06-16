// DesignPatten.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "MutiThreadDebug.h"

#include "RefineAbstraction.h"
#include "ConcreteImplementor.h"
#include "Invoker.h"
#include "ConcreteCommand.h"
#include "ConcreteElement.h"
#include "ConcreteVisitor.h"
void testBridge() {
	std::cout << "bridge test" << std::endl;
	Abstraction* abstraction = new RefineAbstraction(new ConcreteImplementor());
	abstraction->show();
}

void testCommand() {
	Invoker* invoker = new Invoker(new ConcreteCommand(new Receiver));
	invoker->show();
}
#include "ConcreteSubject.h"
#include"ConcreteObserver.h"
void testObserver(){
	Subject* subject = new ConcreteSubject();
	for (int i=0;i<10;++i){
		subject->attach(new ConcreteObserver(subject));
	}

	subject->notify();
}


void testVisitor(){
	Element*element = new ConcreteElement();
	Visitor*visitor = new ConcreteVisitor();
	element->accept(visitor);
	visitor->visit(element);
}

int main()
{
	//testCommand();
	//testBridge();

	//testObserver();
	testVisitor();

	return 0;
}

