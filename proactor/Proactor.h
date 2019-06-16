#pragma once
#include <Windows.h>
class Proactor
{
public:
	Proactor();
	virtual ~Proactor();

	void register_handle(int fd);
	void handle_events();




private:
	HANDLE completionPort_{INVALID_HANDLE_VALUE};
};
