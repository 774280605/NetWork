#include "pch.h"
#include "LFEventHandler.h"
#include "LFLoggingHandler.h"
#include <WinSock2.h>
#include "LoggingHandler.h"
LFEventHandler::LFEventHandler(Reactor*reactor,LFThreadPool* lfThreadPool, EventHandler* eventHandler):lfThreadPool_(lfThreadPool),
concreteEventHandler_(eventHandler),
reactor_(reactor)
{
	reactor_->register_handle(this,READ_EVENT);
}

LFEventHandler::~LFEventHandler(){
}

int LFEventHandler::handleInput(int fd){
	lfThreadPool_->deactivate(fd, READ_EVENT);
	lfThreadPool_->promote_new_leader();
	int accept =  concreteEventHandler_->handleInput(fd);
	auto concreteHandler = new LoggingHandler(reactor_,accept);
	auto lfHandler = new LFLoggingHandler(reactor_,lfThreadPool_,concreteHandler);

	lfThreadPool_->reactivate(fd, READ_EVENT);
	return 0;
}

void LFEventHandler::handleOutput(int fd){

}

void LFEventHandler::handleTimeout(int fd){
}

void LFEventHandler::handleClose(int fd, Event_Type type){
}

int LFEventHandler::getHandle(){
	return concreteEventHandler_->getHandle();
}

void LFEventHandler::handleEvent(int fd, Event_Type type){
}

void LFEventHandler::startUp(){
	
}
