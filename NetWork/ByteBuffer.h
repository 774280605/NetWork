#pragma once
#include<cstdint>
class ByteBuffer
{
public:
	ByteBuffer();
	virtual ~ByteBuffer();

	int append(char*data,int len);
	int remove(char*buffer,int len);
	int read(int fd,int howmuch);

	int getLength();
private:
	uint32_t readIndex_;
	uint32_t writeIndex_;
	char* buffer_;

	uint32_t capacity_;


private:
	int expand(uint32_t len);
	void align();
	int drain(uint32_t len);
};
