#include "pch.h"
#include "LoggingAccept.h"
#include <WinSock2.h>
#include "LoggingHandler.h"
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)
LoggingAccept::LoggingAccept(Reactor*reactor):reactor_(reactor){
	this->setup();
	reactor_->register_handle(this,READ_EVENT);
}

LoggingAccept::~LoggingAccept(){
}

int LoggingAccept::getHandle(){
	return fd_;
}

void LoggingAccept::handleEvent(int fd, Event_Type type){
	if (type==READ_EVENT){
		//todo accept 有连接事件
		struct sockaddr_in sin;
		int len = sizeof(sin);

		unsigned int acceptfd= accept(fd_, (struct sockaddr*)&sin, &len);
		send(acceptfd, "zhangxiaofei", 12, 0);

	}
}

void LoggingAccept::handleInput(int fd){
	struct sockaddr_in sin;
	int len = sizeof(sin);

	unsigned int acceptfd = accept(fd_, (struct sockaddr*)&sin, &len);
	auto tmpClient = new LoggingHandler(reactor_, acceptfd);

}

void LoggingAccept::handleOutput(int fd){
}

void LoggingAccept::handleTimeout(int fd){
}

void LoggingAccept::handleClose(int fd, Event_Type type){
}

void LoggingAccept::setup(){
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {	
		
	}

	fd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd_ == INVALID_SOCKET) {		
		WSACleanup();		
	}

	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);

	if (bind(fd_,(SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR) {
		closesocket(fd_);
		WSACleanup();		
	}

	if (listen(fd_, 1) == SOCKET_ERROR) {
		closesocket(fd_);
		WSACleanup();		
	}
}
