#include "pch.h"
#include "LoggingHandler.h"
#include <WinSock2.h>
#include <iostream>

LoggingHandler::LoggingHandler(Reactor*reactor,int fd):reactor_(reactor),fd_(fd){
	reactor_->register_handle(this, READ_EVENT);
	//reactor_->register_handle(this, WRITE_EVENT);
}

LoggingHandler::~LoggingHandler(){
}

int LoggingHandler::getHandle(){
	return fd_;
}

void LoggingHandler::handleEvent(int fd, Event_Type type){
	if (type== READ_EVENT){
		//sock_stream_.recv();
	}
	else if(type==CLOSE_EVENT){
		//sock_stream.close();
	}
}

void LoggingHandler::handleInput(int fd){
	char szbuffer[1024] = { 0 };
	recv(fd_, szbuffer, 1024, 0);
	std::cout << szbuffer;
}

void LoggingHandler::handleOutput(int fd){
	send(fd_, "zhangxiaofei11111", 18, 0);
}

void LoggingHandler::handleTimeout(int fd){
}

void LoggingHandler::handleClose(int fd, Event_Type type){

}
