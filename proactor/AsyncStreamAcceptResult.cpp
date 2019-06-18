#include "pch.h"
#include "AsyncStreamAcceptResult.h"

AsyncStreamAcceptResult::AsyncStreamAcceptResult(CompletionHandler* completionHandler){
	this->completionHandler_ = completionHandler;
}

AsyncStreamAcceptResult::~AsyncStreamAcceptResult(){
}

void AsyncStreamAcceptResult::complete(){
	completionHandler_->handle_accept(completionHandler_->get_handle(), *this);
}
