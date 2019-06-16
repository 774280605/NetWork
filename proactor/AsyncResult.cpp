#include "pch.h"
#include "AsyncResult.h"

AsyncResult::AsyncResult(){
}

AsyncResult::~AsyncResult(){
}

void AsyncResult::bytesTransferred(unsigned long bytes){
	this->bytesTransferred_ = bytes;
}

unsigned long AsyncResult::bytesTransferred(){
	return this->bytesTransferred_;
}

unsigned long AsyncResult::statue(){
	return this->statue_;
}

void AsyncResult::statue(unsigned long statue){
	this->statue_ = statue;
}

void AsyncResult::error(unsigned long error){
	this->error_ = error;
}

unsigned long AsyncResult::error(){

	return this->error_;
}
