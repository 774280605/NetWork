#include "pch.h"
#include "MutiThreadDebug.h"
#include <iostream>

MutiThreadDebug::MutiThreadDebug() {
}


MutiThreadDebug::~MutiThreadDebug() {
}

void MutiThreadDebug::setup() {
	for (int i=0;i< 4;i++) {
		threads_.emplace_back(work);
	}



}

void MutiThreadDebug::stop() {
	for (auto& entry:threads_) {
		entry.join();
	}
}

void MutiThreadDebug::work() {
	int* newB = new int();
	*newB = 1;
	
	std::cout << "wowoowowowo:"<< std::this_thread::get_id();

}
