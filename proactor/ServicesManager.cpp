#include "pch.h"
#include "ServicesManager.h"

void ServicesManager::add(CompletionHandler* completionHandler){
	servicesManager_[completionHandler->get_handle()] = completionHandler;
}

void ServicesManager::remove(CompletionHandler* completionHandler){
	auto tmpHandler= servicesManager_.find(completionHandler->get_handle());
	if (tmpHandler!= servicesManager_.end()){
		servicesManager_.erase(tmpHandler);
	}
}

bool ServicesManager::contain(CompletionHandler* completionHandler){
	auto tmpHandler = servicesManager_.find(completionHandler->get_handle());
	return tmpHandler != servicesManager_.end();
}

CompletionHandler* ServicesManager::find(uintmax_t fd){
	auto tmpHandler = servicesManager_.find(fd);
	if (tmpHandler!= servicesManager_.end()){
		return tmpHandler->second;
	}
	return nullptr;
}
