#include "pch.h"
#include "Proactor.h"
#include<Windows.h>
#include <cstdio>

Proactor::Proactor(){
	completionPort_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 
		nullptr, 0, 0);
	if (completionPort_==INVALID_HANDLE_VALUE){
		printf("CreateIoCompletionPort failed!\n");
	}
}

Proactor::~Proactor(){
}

void Proactor::register_handle(int fd){
	auto h = CreateIoCompletionPort((HANDLE)fd, completionPort_, 0, 0);
	if (h==INVALID_HANDLE_VALUE){
		printf("CreateIoCompletionPort fali!\n");
	}
}

void Proactor::handle_events(){






}
