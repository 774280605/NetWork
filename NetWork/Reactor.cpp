#include "pch.h"
#include "Reactor.h"
#include "SelectReactorImpl.h"
#include "LFSelectReactorImpl.h"

Reactor::Reactor(){
	impl_ = new LFSelectReactorImpl();
}

Reactor::~Reactor(){
}

void Reactor::register_handle(EventHandler* handler, Event_Type type){
	impl_->register_handle(handler, type);
}

void Reactor::register_handle(int fd, EventHandler* handler, Event_Type type){
	impl_->register_handle(fd, handler, type);
}

void Reactor::remove_handle(EventHandler* handler, Event_Type type){
	impl_->remove_handle(handler, type);
}

void Reactor::remove_handle(int fd, Event_Type type){
	impl_->remove_handle(fd, type);
}

void Reactor::handle_events(){
	impl_->handle_events();
}

