#include "pch.h"
#include "Proactor.h"
#include <WinSock2.h>
#include <cstdio>
#include "AsyncResult.h"
Proactor::Proactor(){
	completionPort_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 
		nullptr, 0, 0);
	if (completionPort_==INVALID_HANDLE_VALUE){
		printf("CreateIoCompletionPort failed!\n");
	}
}

Proactor::~Proactor(){
}

void Proactor::register_handle(uintmax_t fd){
	auto h = CreateIoCompletionPort((HANDLE)fd, completionPort_, 0, 0);
	if (h==INVALID_HANDLE_VALUE){
		printf("CreateIoCompletionPort fali!\n");
	}
}

void Proactor::handle_events(){
	DWORD transferBytes = 0;
	uintmax_t completionKey;
	OVERLAPPED*overlapped;
	bool statue= GetQueuedCompletionStatus(completionPort_, &transferBytes, &completionKey, &overlapped, INFINITE);

	AsyncResult* asyncResult = static_cast<AsyncResult*>(overlapped);

	asyncResult->statue(statue);
	if (!statue){
		asyncResult->error(WSAGetLastError());
	}
	else{
		asyncResult->bytesTransferred(transferBytes);
	}

	asyncResult->complete();

	delete asyncResult;

}
