#pragma once

class DataBlock
{



public:
	DataBlock();
	virtual ~DataBlock();

	long getDataLen()const;
	long getTotalLen()const;
	long add(void*data, long len);
	long remove(void*buffer,long len);
	DataBlock*next()const;
	void next(DataBlock*block);
	long space()const;
	long duplicate(char*buffer, long len) const;
private:
	int blockExpand(long len);
	void blockAlign();

//private:
	char*buffer_{nullptr};
	long misalign_{};
	long totalLen_{};
	long off_{};
	DataBlock*next_{nullptr};
};
