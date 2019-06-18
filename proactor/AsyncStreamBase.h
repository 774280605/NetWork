#pragma once
#include <cstdint>

class Proactor;
class CompletionHandler;

class AsyncStreamBase
{
public:
	AsyncStreamBase()=default;
	virtual ~AsyncStreamBase()=default;
	virtual  void open(uintmax_t fd, CompletionHandler*handler, Proactor*proactor)=0;
	virtual  void async_read(void*buffer, unsigned long bytes)=0;
	virtual  void async_write(void*buffer, unsigned long bytes)=0;
};
