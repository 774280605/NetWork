#include "pch.h"
#include "Session.h"
#include <iostream>

Session::Session(uintmax_t fd, Proactor* proactor):CompletionHandler(proactor),fd_(fd){
	asyncStream_ = new AsyncStream();
	asyncStream_->open(fd, this, proactor);
	asyncStream_->async_read(buffer_,1024);
}

Session::~Session(){
}

void Session::handle_read(uintmax_t fd, const AsyncResult& result){
	std::cout << buffer_ << std::endl;

}

void Session::handle_write(uintmax_t fd, const AsyncResult& result){
}

void Session::handle_accept(uintmax_t fd, const AsyncResult& result){
}

uintmax_t Session::get_handle(){
	return this->fd_;
}
