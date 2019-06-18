#pragma once
#include "AsyncResult.h"
#include "CompletionHandler.h"
class AsyncStreamAcceptResult:public AsyncResult
{
public:
	AsyncStreamAcceptResult(CompletionHandler*completionHandler);
	virtual ~AsyncStreamAcceptResult();


	void complete() override;


private:
	CompletionHandler*completionHandler_{nullptr};
};
