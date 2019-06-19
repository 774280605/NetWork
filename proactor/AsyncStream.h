#pragma once
#include"CompletionHandler.h"
#include <cstdint>
#include "AsyncStreamBase.h"
class AsyncStream:public AsyncStreamBase
{
public:
	AsyncStream();
	virtual ~AsyncStream();
	void open(uintmax_t fd, CompletionHandler*handler, Proactor*proactor) override;
	void async_read(void*buffer, unsigned long bytes) override;
	void async_write(void*buffer, unsigned long bytes)override;
private:
	CompletionHandler* handler{nullptr};
	uintmax_t fd_{INVALID_SOCKET};
	Proactor*proactor_{nullptr};

};
