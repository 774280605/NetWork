#pragma once
#include "ReactorImpl.h"
#include <map>
#include <WinSock2.h>
class SelectReactorImpl:public ReactorImpl
{
public:
	SelectReactorImpl();
	virtual ~SelectReactorImpl();


	void register_handle(EventHandler* handler, Event_Type type) override;
	void register_handle(int fd, Event_Type type) override;
	void remove_handle(EventHandler* handler, Event_Type type) override;
	void remove_handle(int fd, Event_Type type) override;

	void handle_events() override;
private:
	std::map < uint32_t, EventHandler* > table_;
	fd_set readfds, writefds, exceptionfds;
};
