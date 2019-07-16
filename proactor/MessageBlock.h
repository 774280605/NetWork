#pragma once
#include <cstdint>
class DataBlock;

class MessageBlock
{
public:
	MessageBlock();
	virtual ~MessageBlock();

	int add(char* data, long len);
	int remove(char*buffer,long len);

	int read_n(uintmax_t fd,long len);
	int write_n(uintmax_t fd,long len);
	long length()const;
private:
	void freeBlock();

private:
	DataBlock*first_{nullptr};
	DataBlock*last_{nullptr};
	
	long totalLen_{};
};
