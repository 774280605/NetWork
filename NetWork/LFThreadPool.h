#pragma once
#include <mutex>
#include "Reactor.h"
class LFThreadPool
{
public:
	LFThreadPool(Reactor*reactor);
	virtual ~LFThreadPool();

	void join();
	void promote_new_leader();
	void deactivate(int fd, Event_Type type);
	void reactivate(int fd, Event_Type type);

private:
	std::mutex mutex_;
	std::condition_variable conditionVariable_;
	std::thread::id leaderId_;

	std::thread::id noCurrentId_;
	Reactor*reactor_;
};
