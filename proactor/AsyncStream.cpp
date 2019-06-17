#include "pch.h"
#include "AsyncStream.h"
#include <WinSock2.h>
#include "AsyncStreamReadResult.h"
#pragma comment(lib,"ws2_32.lib")
AsyncStream::AsyncStream(){
}

AsyncStream::~AsyncStream(){
}

void AsyncStream::open(uintmax_t fd, CompletionHandler* handler, Proactor* proactor){
	this->fd_ = fd;
	this->handler = handler;
	this->proactor_ = proactor;
	this->proactor_->register_handle(fd);
}

void AsyncStream::async_read(void* buffer, unsigned long bytes){

	DWORD tranferBytes = 0;
	DWORD flags = 0;
	WSABUF wsabuf;
	wsabuf.buf = static_cast<char*>(buffer);
	wsabuf.len = bytes;
	OVERLAPPED* act = new AsyncStreamReadResult(handler);
	int result= WSARecv(fd_, &wsabuf,1,&tranferBytes,&flags,act,nullptr);
	if (result){
		int errCode = WSAGetLastError();
		if (errCode!= WSA_IO_PENDING){
			return;
		}
	}
	return;
}

void AsyncStream::async_write(void* buffer, unsigned long bytes){

}
