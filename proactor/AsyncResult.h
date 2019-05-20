﻿#pragma once
#include<Windows.h>

class AsyncResult:public OVERLAPPED
{
public:
	AsyncResult();
	virtual ~AsyncResult();

	virtual void complete() = 0;
	void bytesTransferred(unsigned long);
	unsigned long bytesTransferred();

	unsigned long statue();
	void statue(unsigned long);

	void error(unsigned long);
	unsigned long error();
};