#include "pch.h"
#include "AsyncStreamReadResult.h"

AsyncStreamReadResult::AsyncStreamReadResult(CompletionHandler* handler):handler_(handler){

}

AsyncStreamReadResult::~AsyncStreamReadResult(){
}

void AsyncStreamReadResult::complete(){
	   
	handler_->handle_read(handler_->get_handle(), *this);
}
