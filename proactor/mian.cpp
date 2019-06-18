// proactor.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Acceptor.h"
int main()
{
	Proactor* proactor = new Proactor;
	Acceptor* acceptor = new Acceptor(proactor);
	acceptor->setup();
	while (true){
		proactor->handle_events();
	}
}
