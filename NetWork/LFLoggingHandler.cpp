#include "pch.h"
#include "LFLoggingHandler.h"

LFLoggingHandler::LFLoggingHandler(Reactor*reactor, LFThreadPool*lfThreadPool, EventHandler*handler):
lfThreadPool_(lfThreadPool),
reactor_(reactor),
concreteEventHandler_(handler)
{
	reactor_->register_handle(this, concreteEventHandler_->getHandle());
}

LFLoggingHandler::~LFLoggingHandler(){
}

int LFLoggingHandler::handleInput(int fd){

	lfThreadPool_->deactivate(fd, READ_EVENT);

	lfThreadPool_->promote_new_leader();
	concreteEventHandler_->handleInput(fd);
	lfThreadPool_->reactivate(fd, READ_EVENT);

	return 0;
}

void LFLoggingHandler::handleOutput(int fd){
}

void LFLoggingHandler::handleTimeout(int fd){
}

void LFLoggingHandler::handleClose(int fd, Event_Type type){
}

int LFLoggingHandler::getHandle(){
	return this->concreteEventHandler_->getHandle();
}

void LFLoggingHandler::handleEvent(int fd, Event_Type type){
}
