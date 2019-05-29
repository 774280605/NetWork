#include "pch.h"
#include "LFLoggingHandler.h"

LFLoggingHandler::LFLoggingHandler(Reactor*reactor, LFThreadPool*lfThreadPool, EventHandler*handler):
lfThreadPool_(lfThreadPool),
reactor_(reactor),
concreteEventHandler_(handler)
{
}

LFLoggingHandler::~LFLoggingHandler(){
}

void LFLoggingHandler::handleInput(int fd){


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
