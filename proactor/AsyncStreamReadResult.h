#pragma once
#include"CompletionHandler.h"
#include"AsyncResult.h"
class AsyncStreamReadResult:public AsyncResult
{
public:
	AsyncStreamReadResult(CompletionHandler*handler);
	virtual ~AsyncStreamReadResult();
	void complete()override;

private:
	CompletionHandler*handler_;
};
