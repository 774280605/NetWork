#include "pch.h"
#include "SelectReactorImpl.h"
#pragma comment(lib,"ws2_32.lib")
SelectReactorImpl::SelectReactorImpl(){
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);
	FD_ZERO(&exceptionfds);
}

SelectReactorImpl::~SelectReactorImpl(){

}

void SelectReactorImpl::register_handle(EventHandler* handler, Event_Type type){
	if (type==READ_EVENT){
		FD_SET(handler->getHandle(), &readfds);
		table_[handler->getHandle()] = handler;
	}else if (type == WRITE_EVENT){
		FD_SET(handler->getHandle(), &writefds);
		table_[handler->getHandle()] = handler;
	}
	
}

void SelectReactorImpl::register_handle(int fd, Event_Type type){
	if (type == READ_EVENT){
		FD_SET(fd, &readfds);
	}else if (type == WRITE_EVENT){
		FD_SET(fd, &writefds);
	}
	
	//table_[handler->getHandle()] = handler;
}

void SelectReactorImpl::remove_handle(EventHandler* handler, Event_Type type){
	if (type==READ_EVENT){
		FD_CLR(handler->getHandle(),&readfds);
	}else if (type==WRITE_EVENT){
		FD_CLR(handler->getHandle(), &writefds);
	}
}

void SelectReactorImpl::remove_handle(int fd, Event_Type type){

	if (type == READ_EVENT) {
		FD_CLR(fd, &readfds);
	}
	else if (type == WRITE_EVENT) {
		FD_CLR(fd, &writefds);
	}
}

void SelectReactorImpl::handle_events(){
	
	while (true){
		int nfds = select(5, &readfds, &writefds, &exceptionfds,nullptr);

		if (nfds>0){
			for (auto element:table_){
				if (FD_ISSET( element.first,&readfds)){
					element.second->handleInput(element.first);
				}
				if (FD_ISSET(element.first,&writefds)){
					element.second->handleOutput(element.first);
				}
			}
		}	
			
	}

}
