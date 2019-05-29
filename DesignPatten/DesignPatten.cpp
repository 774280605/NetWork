// DesignPatten.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "MutiThreadDebug.h"

#include "RefineAbstraction.h"
#include "ConcreteImplementor.h"
#include "Invoker.h"
#include "ConcreteCommand.h"
void testBridge() {
	std::cout << "bridge test" << std::endl;
	Abstraction* abstraction = new RefineAbstraction(new ConcreteImplementor());
	abstraction->show();
}

void testCommand() {
	Invoker* invoker = new Invoker(new ConcreteCommand(new Receiver));
	invoker->show();
}

int main()
{
	testCommand();
	//testBridge();
	return 0;
}

