#pragma once
#include"global.h"
#include"AsyncResult.h"
#include"Proactor.h"
class CompletionHandler
{
public:
	CompletionHandler(Proactor*proactor);
	virtual ~CompletionHandler();
	virtual void handle_read(uintmax_t fd, const AsyncResult&result)=0;
	virtual void handle_write(uintmax_t fd, const AsyncResult&result) = 0;
	virtual void handle_accept(uintmax_t fd, const AsyncResult&result) = 0;
	virtual uintmax_t get_handle() =0;

protected:
	Proactor*proactor_;
};
