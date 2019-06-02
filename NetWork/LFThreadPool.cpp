#include "pch.h"
#include "LFThreadPool.h"

LFThreadPool::LFThreadPool(Reactor*reactor)
	:reactor_(reactor)
{
}

LFThreadPool::~LFThreadPool(){

}

void LFThreadPool::join(){
	std::unique_lock<std::mutex> lock(mutex_);


	for (;;){
		while (leaderId_!=noCurrentId_){
			conditionVariable_.wait(lock);
		}

		//dispatch
		leaderId_ = std::this_thread::get_id();
		lock.unlock();
		reactor_->handle_events();

		
		lock.lock();
	}
}

void LFThreadPool::promote_new_leader(){
	std::unique_lock<std::mutex> lock(mutex_);
	if (leaderId_!= std::this_thread::get_id()){
		return;
	}


	leaderId_ = noCurrentId_;
	conditionVariable_.notify_one();

}

void LFThreadPool::deactivate(int fd, Event_Type type){
	reactor_->remove_handle(fd, type);
}

void LFThreadPool::reactivate(int fd, Event_Type type){
	reactor_->register_handle(fd, type);
}
