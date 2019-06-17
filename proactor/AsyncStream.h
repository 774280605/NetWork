#pragma once
#include"CompletionHandler.h"
#include <cstdint>

class AsyncStream
{
public:
	AsyncStream();
	virtual ~AsyncStream();
	void open(uintmax_t fd, CompletionHandler*handler, Proactor*proactor);
	void async_read(void*buffer, unsigned long bytes);
	void async_write(void*buffer, unsigned long bytes);
private:
	CompletionHandler* handler{nullptr};
	uintmax_t fd_{INVALID_SOCKET};
	Proactor*proactor_{nullptr};


};
