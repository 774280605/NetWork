#pragma once
#include "AsyncStreamBase.h"
class AcceptorAsyncStream:public AsyncStreamBase
{
public:
	AcceptorAsyncStream()=default;
	virtual ~AcceptorAsyncStream()=default;


	void open(uintmax_t fd, CompletionHandler* handler, Proactor* proactor) override;
	void async_read(void* buffer, unsigned long bytes) override;
	void async_write(void* buffer, unsigned long bytes) override;



private:
	uintmax_t fd_{0};
	CompletionHandler* completionHandler_{nullptr};
	Proactor*proactor_{nullptr};
};
