#pragma once
#include<WinSock2.h>
#include<Windows.h>

class AsyncResult:public OVERLAPPED
{
public:
	AsyncResult();
	virtual ~AsyncResult();

	virtual void complete() = 0;
	void bytesTransferred(unsigned long);
	unsigned long bytesTransferred();

	bool statue();
	void statue(bool statue);

	void error(unsigned long);
	unsigned long error();
private:
	bool statue_;
	unsigned long error_;
	unsigned long bytesTransferred_;

};
 