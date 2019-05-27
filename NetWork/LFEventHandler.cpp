#include "pch.h"
#include "LFEventHandler.h"

LFEventHandler::LFEventHandler(LFThreadPool* lfThreadPool, EventHandler* eventHandler):lfThreadPool_(lfThreadPool),
concreteEventHandler_(eventHandler)

{
}

LFEventHandler::~LFEventHandler(){
}

void LFEventHandler::handleInput(int fd){
	lfThreadPool_->deactivate(fd, READ_EVENT);
	lfThreadPool_->promote_new_leader();
	concreteEventHandler_->handleInput(fd);
	lfThreadPool_->reactivate(fd, READ_EVENT);
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
