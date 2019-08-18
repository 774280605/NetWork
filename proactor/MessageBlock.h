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
	int resize(long len);
private:
	void freeBlock();

private:
	DataBlock*first_{nullptr};
	DataBlock*last_{nullptr};
	DataBlock*last_with_data_{nullptr};
	
	long totalLen_{};
};
