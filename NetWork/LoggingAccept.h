#pragma once
#include "EventHandler.h"
#include <cstdint>
#include "Reactor.h"

class LoggingAccept:public EventHandler
{
public:
	LoggingAccept(Reactor*reactor);
	virtual ~LoggingAccept();


	int getHandle() override;
	void handleEvent(int fd, Event_Type type) override;


	void handleInput(int fd) override;
	void handleOutput(int fd) override;
	void handleTimeout(int fd) override;
	void handleClose(int fd, Event_Type type) override;
	void setup();

private:
	uint32_t fd_;
	Reactor* reactor_;
	//sock_acceptor acceptor;
};
