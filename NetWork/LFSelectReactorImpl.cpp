#include "pch.h"
#include "LFSelectReactorImpl.h"

LFSelectReactorImpl::LFSelectReactorImpl(){	
	FD_ZERO(&readfds);	
	FD_ZERO(&writefds);
	FD_ZERO(&exceptionfds);
}

LFSelectReactorImpl::~LFSelectReactorImpl(){
}

void LFSelectReactorImpl::register_handle(EventHandler* handler, Event_Type type){
	if (type == READ_EVENT) {
		FD_SET(handler->getHandle(), &readfds);
		table_[handler->getHandle()] = handler;
	}
	else if (type == WRITE_EVENT) {
		FD_SET(handler->getHandle(), &writefds);
		table_[handler->getHandle()] = handler;
	}
}

void LFSelectReactorImpl::register_handle(int fd, EventHandler* handler, Event_Type type){
	if (type == READ_EVENT) {
		FD_SET(fd, &readfds);
	}
	else if (type == WRITE_EVENT) {
		FD_SET(fd, &writefds);
	}

	table_[handler->getHandle()] = handler;
}

void LFSelectReactorImpl::remove_handle(EventHandler* handler, Event_Type type){
	if (type == READ_EVENT) {
		FD_CLR(handler->getHandle(), &readfds);
	}
	else if (type == WRITE_EVENT) {
		FD_CLR(handler->getHandle(), &writefds);
	}
}

void LFSelectReactorImpl::remove_handle(int fd, Event_Type type){
	if (type == READ_EVENT) {
		FD_CLR(fd, &readfds);
	}
	else if (type == WRITE_EVENT) {
		FD_CLR(fd, &writefds);
	}
}

void LFSelectReactorImpl::handle_events(){
	int nfds = select(5, &readfds, &writefds, &exceptionfds, nullptr);
	int error = GetLastError();
	if (nfds > 0) {
		for (auto element : table_) {
			if (FD_ISSET(element.first, &readfds)) {
				element.second->handleInput(element.first);
			}
			if (FD_ISSET(element.first, &writefds)) {
				element.second->handleOutput(element.first);
			}
		}
	}
}
