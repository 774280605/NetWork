#pragma once
#include "CompletionHandler.h"
#include "AsyncStream.h"
#include "AsyncStreamReadResult.h"
class Session:public CompletionHandler
{
public:
	Session(uintmax_t fd,Proactor*proactor);
	virtual ~Session();


	void handle_read(uintmax_t fd, const AsyncResult& result) override;
	void handle_write(uintmax_t fd, const AsyncResult& result) override;
	void handle_accept(uintmax_t fd, const AsyncResult& result) override;
	uintmax_t get_handle() override;

private:
	uintmax_t fd_{0};
	AsyncStreamBase* asyncStream_{nullptr};
	char buffer_[1024]{ 0 };

};
