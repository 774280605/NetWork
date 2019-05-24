#pragma once
#include"global.h"
#include"AsyncResult.h"
#include"Proactor.h"
class CompletionHandler
{
public:
	CompletionHandler();
	virtual ~CompletionHandler();
	virtual void handle_read(int fd, const AsyncResult&result)=0;
	virtual void handle_write(int fd, const AsyncResult&result) = 0;
	virtual void handle_accept(int fd, const AsyncResult&result) = 0;
	virtual int get_handle()=0;

private:
	Proactor*proactor_;
};
