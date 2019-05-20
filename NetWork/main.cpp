// Reactor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "LoggingAccept.h"

int main()
{
	Reactor*reactor = new Reactor;
    std::cout << "Hello World!\n";
	LoggingAccept accept(reactor);

	reactor->handle_events();
}

