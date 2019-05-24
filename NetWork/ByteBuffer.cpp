#include "pch.h"
#include "ByteBuffer.h"
#include<cstdlib>
#include<cstring>
#include<WinSock2.h>
ByteBuffer::ByteBuffer() :
readIndex_(0),
writeIndex_(0),
capacity_(0),
buffer_(nullptr)
{
}

ByteBuffer::~ByteBuffer(){
}

int ByteBuffer::append(char* data, int len){
	uint32_t need = writeIndex_ + len;
	if (capacity_<need) {
		if (expand(len) == -1)
			return -1;
	}

	memcpy(buffer_+writeIndex_,data,len);
	writeIndex_ += len;
	return 0;
}

int ByteBuffer::remove(char* buffer, int len){
	uint32_t nread = len;
	if (nread>=(writeIndex_-readIndex_)) {
		nread = (writeIndex_-readIndex_);
	}
	std::memcpy(buffer,buffer_+readIndex_,nread);
	drain(nread);
	return nread;
}

int ByteBuffer::read(int fd, int howmuch){
	unsigned long n = 4096;
	
	if (ioctlsocket(fd, FIONREAD, &n)==-1 || n==0) {
		n = 4096;
	}
	if (howmuch<=-1 || howmuch>n) {
		howmuch = n;
	}

	if (expand(howmuch) == -1)
		return -1;
	char* p = buffer_ + writeIndex_;

	n = recv(fd,p,howmuch,0);
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	writeIndex_ += n;
	return n;
}

int ByteBuffer::getLength(){
	return writeIndex_ - readIndex_;
}

/*				readindex		writeindex   capacity
 * |---------------|------------|-------------|
 *
 */

int ByteBuffer::expand(uint32_t len){
	uint32_t need = writeIndex_ + len;
	if (capacity_ >= need)
		return 0;

	if (readIndex_>=len) {
		align();
	}
	else {
		void* newBuf;
		uint32_t length = capacity_;
		if (length < 256) {
			length = 256;
		}
		while (length<need) {
			length <<= 1;
		}

		if (readIndex_!=0) {
			align();
		}

		if ((newBuf=std::realloc(buffer_,length))==nullptr) {
			return -1;
		}

		buffer_ = static_cast<char*>(newBuf);
		capacity_ = length;
	}

	return 0;
}

void ByteBuffer::align(){
	uint32_t need = writeIndex_ - readIndex_;
	std::memmove(buffer_,buffer_+readIndex_,need);
	readIndex_ = 0;
	writeIndex_ = need;
}

int ByteBuffer::drain(uint32_t len){
	uint32_t need = len;

	if (need>=(writeIndex_-readIndex_)) {
		writeIndex_ = readIndex_ = 0;
	}

	readIndex_ += len;
	return 0;
}
