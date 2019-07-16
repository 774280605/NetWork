#include "DataBlock.h"
#include <cstring>
#include <cstdlib>

DataBlock::DataBlock(){
}

DataBlock::~DataBlock(){

}

long DataBlock::getDataLen() const{
	return this->off_;
}

long DataBlock::getTotalLen() const{
	return this->totalLen_;
}

long DataBlock::add(void* data, long len){
	long need = this->misalign_ + this->off_ + len;
	if(need>totalLen_){
		if (blockExpand(len) == -1)
			return -1;
	}
	memcpy(buffer_+off_, data, len);
	off_ += len;
	return(len);
}

long DataBlock::remove(void* buffer, long len){
	long need = 0;
	if(len>off_){
		need = off_;
	}
	else{
		need = len;
	}
	memcpy(buffer, buffer_ + misalign_, need);
	misalign_ += need;
	off_ -= need;

	return (need);
}

DataBlock* DataBlock::next() const{
	return this->next_;
}

void DataBlock::next(DataBlock* block){
	this->next_ = block;
}

long DataBlock::space() const{
	return totalLen_ - off_;
}

long DataBlock::duplicate(char* buffer, const long len) const{
	long need = 0;
	if (len > off_) {
		need = off_;
	}
	else {
		need = len;
	}
	memcpy(buffer, buffer_ + misalign_, need);
	return (need);
}

#define		MAX_BUFFER_LEN 4096
int DataBlock::blockExpand(long len){
	int need = misalign_ + off_ + len;
	if(need<=totalLen_)
		return 0;
	if (misalign_>=len)
		blockAlign();
	else{
		void*newBuf;
		long length = totalLen_;
		if (length<5)
			length = 5;
		while (length<need)
			length <<= 1;
		if (misalign_)
			blockAlign();
		if ((newBuf = realloc(buffer_, length)) == nullptr)
			return -1;

		buffer_ = static_cast<char*>(newBuf);
		totalLen_ = length;
	}
	return 0;
}

void DataBlock::blockAlign(){
	memmove(buffer_, buffer_+misalign_, off_);
	misalign_ = 0;
}
