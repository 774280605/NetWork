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
	std::thread::native_handle_type threadId_;
};
