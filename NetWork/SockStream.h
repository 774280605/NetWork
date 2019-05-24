#pragma once
#include<cstdint>
#include"ByteBuffer.h"
class SockStream
{
public:
	SockStream();
	virtual ~SockStream();

	int read(void*buffer,int len);
	int write(void* buffer,int len);
	int read();
	int getLength();
private:
	uint32_t socket_;
public:
	uint32_t getSocket() const;
	void setSocket(uint32_t socket);

	ByteBuffer readBuffer_;
	ByteBuffer writeBuffer_;

};
