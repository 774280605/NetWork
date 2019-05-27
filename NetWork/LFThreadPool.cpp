#include "pch.h"
#include "LFThreadPool.h"

void LFThreadPool::join(){
	std::unique_lock<std::mutex> lock(mutex_);


	for (;;){
		while (leaderId_!=noCurrentId_){
			conditionVariable_.wait(lock);
		}

		//dispatch

		

	}
}
