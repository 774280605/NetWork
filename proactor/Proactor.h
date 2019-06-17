#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <cstdint>
class Proactor
{
public:
	Proactor();
	virtual ~Proactor();

	void register_handle(uintmax_t fd);
	void handle_events();




private:
	HANDLE completionPort_{INVALID_HANDLE_VALUE};
};
