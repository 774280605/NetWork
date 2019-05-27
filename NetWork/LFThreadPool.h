#pragma once
#include <mutex>

class LFThreadPool
{
public:
	LFThreadPool();
	virtual ~LFThreadPool();

	void join();
	void promote_new_leader();

private:
	std::mutex mutex_;
	std::condition_variable conditionVariable_;
	std::thread::id leaderId_;

	std::thread::id noCurrentId_;
};
