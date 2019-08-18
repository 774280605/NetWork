#include "MessageBlock.h"
#include "DataBlock.h"


MessageBlock::MessageBlock(){
}

MessageBlock::~MessageBlock(){
}

int MessageBlock::add(char* data, long len){

	if (last_==nullptr){
		auto tmpBlock = new DataBlock();
		tmpBlock->add(data, len);
		last_with_data_= first_ = last_ = tmpBlock;

	}
	else{
		auto tmpBlock = last_;
		auto tmpSpace = last_->space();
		
		if (len > tmpSpace){
			tmpBlock->add(data, tmpSpace);
			len -= tmpSpace;
			data += tmpSpace;
			auto newBuffer = new DataBlock();
			newBuffer->add(data, len);
			tmpBlock->next(newBuffer);
			last_ = newBuffer;
			last_with_data_ = newBuffer;
		}else{
			last_->add(data, len);
		}		
	}
	totalLen_ += len;
	return len;
}

int MessageBlock::remove(char* buffer, long len){
	if (first_ == nullptr)
		return 0;
	auto tmpFirst = first_;
	auto tmpDataLen = len;
	while (tmpFirst&& tmpDataLen >0){
		auto tmpSpace = tmpFirst->getDataLen();
		if(tmpSpace<=0){
			continue;
		}
		if(tmpSpace<tmpDataLen){
			tmpFirst->remove(buffer, tmpSpace);
			buffer += tmpSpace;
			tmpDataLen -= tmpSpace;			
		}
		else{//tmpSpace>=tmpDataLen
			tmpFirst->remove(buffer, tmpDataLen);
			break;
		}

		tmpFirst = tmpFirst->next();
	}

	freeBlock();
	totalLen_ -= len;
	return 0;
}

int MessageBlock::read_n(uintmax_t fd, long len){

	return 0;
}

int MessageBlock::write_n(uintmax_t fd, long len){

	return 0;
}

long MessageBlock::length()const{
	return totalLen_;
}

int MessageBlock::resize(long len){
	if (last_==nullptr){
		auto tmpBlock = new DataBlock();
		tmpBlock->resize(len);
		first_ = last_ = tmpBlock;
	}
	else{
		auto tmpBlock = new DataBlock();
		tmpBlock->resize(len);
		last_->next(tmpBlock);
		last_ = tmpBlock;

	}
	return 0;
}

void MessageBlock::freeBlock(){
	while (first_&& first_->getDataLen()<=0){
		auto tmpFirst = first_->next();
		delete first_;
		first_ = tmpFirst;
	}
	if (!first_)
		first_ = last_ = nullptr;
}


