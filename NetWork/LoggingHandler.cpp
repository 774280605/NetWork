#include "pch.h"
#include "LoggingHandler.h"
#include <WinSock2.h>
#include <iostream>

LoggingHandler::LoggingHandler(Reactor*reactor,int fd):reactor_(reactor),fd_(fd){
	reactor_->register_handle(this, READ_EVENT);
	stream_.setSocket(fd);
	//reactor_->register_handle(this, WRITE_EVENT);
}

LoggingHandler::~LoggingHandler(){
	reactor_->remove_handle(this, READ_EVENT);
}

int LoggingHandler::getHandle(){
	return fd_;
}

void LoggingHandler::handleEvent(int fd, Event_Type type){
	
}

void LoggingHandler::handleInput(int fd){
	char szbuffer[1024] = { 0 };
	int bytes= stream_.read();
	if (bytes<0){
		int lasterror = GetLastError();
		if (lasterror== WSAEWOULDBLOCK){
			return;
		}
	}else if (bytes==0){
		reactor_->remove_handle(this, READ_EVENT | WRITE_EVENT); 
	}


	std::cout <<"收到字节:"<< stream_.getLength();
	
}

void LoggingHandler::handleOutput(int fd){

}

void LoggingHandler::handleTimeout(int fd){
}

void LoggingHandler::handleClose(int fd, Event_Type type){

}
