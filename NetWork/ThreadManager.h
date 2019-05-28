#pragma once
#include "LFThreadPool.h"
#include <vector>

class ThreadManager
{
public:
	ThreadManager(Reactor*reactor);
	virtual~ThreadManager();
	void startup();
	void work();
	LFThreadPool*getThreadPool();
private:
	LFThreadPool*lfThreadPool_;

	std::vector<std::thread> threads_;
	Reactor* reactor_;
};
