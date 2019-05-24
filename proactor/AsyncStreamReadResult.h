#pragma once
#include"CompletionHandler.h"
#include"AsyncResult.h"
class AsyncStreamReadResult:public AsyncResult
{
public:
	AsyncStreamReadResult();
	virtual ~AsyncStreamReadResult();
	virtual void complete()override;

private:
	CompletionHandler*handler;
};
