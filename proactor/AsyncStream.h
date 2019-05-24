#pragma once
#include"CompletionHandler.h"
class AsyncStream
{
public:
	AsyncStream();
	virtual ~AsyncStream();
	void open(int fd, CompletionHandler*handler);
	void async_read(void*buffer, unsigned long bytes);
	void async_write(void*buffer, unsigned long bytes);
private:
	CompletionHandler* handler;
	int fd;
	Proactor*proactor_;


};
