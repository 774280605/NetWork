#pragma once

class MethodRequest
{
public:
	MethodRequest() = default;
	virtual ~MethodRequest() = default;
	virtual bool can_run()const = 0;
	virtual void call() = 0;
};
