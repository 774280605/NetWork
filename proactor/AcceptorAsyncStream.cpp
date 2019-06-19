#include "pch.h"
#include "AcceptorAsyncStream.h"
#include "Proactor.h"
#include <MSWSock.h>
#include <iostream>
#include "AsyncStreamAcceptResult.h"
#pragma comment(lib, "Ws2_32.lib")
LPFN_ACCEPTEX lpfnAcceptEx = NULL;
GUID GuidAcceptEx = WSAID_ACCEPTEX;



void AcceptorAsyncStream::open(uintmax_t fd, CompletionHandler* handler, Proactor* proactor){
	this->fd_ = fd;
	this->completionHandler_ = handler;
	this->proactor_ = proactor;
	this->proactor_->register_handle(fd);
	DWORD dwBytes = 0;
	auto  iResult = WSAIoctl(fd, SIO_GET_EXTENSION_FUNCTION_POINTER,&GuidAcceptEx, sizeof(GuidAcceptEx),
		&lpfnAcceptEx, sizeof(lpfnAcceptEx),&dwBytes, NULL, NULL);

	if (iResult==SOCKET_ERROR){
		
	}
}

void AcceptorAsyncStream::async_read(void* buffer, unsigned long bytes){
	DWORD transferbytes = 0;
	auto accept = socket(AF_INET,SOCK_STREAM,0);
	unsigned long blocking = 1;
	ioctlsocket(accept, FIONBIO, &blocking);

	OVERLAPPED* overlapped = new AsyncStreamAcceptResult(completionHandler_);
	*(uintmax_t*)buffer = accept;
	const bool ret= lpfnAcceptEx(fd_, accept, buffer_, 0,sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &transferbytes,overlapped);
	if (!ret){
		const auto errCode = WSAGetLastError();
		if(errCode!= WSA_IO_PENDING){
			std::cout << "acceptEx fail!" << std::endl;
		}
		else{
			std::cout << "acceptEx success!" << std::endl;
		}
	}


}

void AcceptorAsyncStream::async_write(void* buffer, unsigned long bytes){
}
