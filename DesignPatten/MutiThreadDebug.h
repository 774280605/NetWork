#pragma once
#include <thread>
#include <vector>

class MutiThreadDebug
{
public:
	MutiThreadDebug();
	virtual ~MutiThreadDebug();


	void setup();
	void stop();

	static void work();

private:
	std::vector<std::thread> threads_;
};

