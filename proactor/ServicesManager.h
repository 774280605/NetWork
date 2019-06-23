#pragma once
#include "CompletionHandler.h"
#include <unordered_map>

class ServicesManager
{
public:
	ServicesManager()=default;
	virtual ~ServicesManager()=default;

	void add(CompletionHandler*completionHandler);
	void remove(CompletionHandler*completionHandler);

	bool contain(CompletionHandler* completionHandler);
	CompletionHandler*find(uintmax_t fd);



private:
	std::unordered_map<uintmax_t, CompletionHandler*> servicesManager_;
};
