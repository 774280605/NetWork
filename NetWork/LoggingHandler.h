#pragma once
#include "EventHandler.h"
#include <cstdint>
#include "Reactor.h"
#include"SockStream.h"
class LoggingHandler:public EventHandler
{
public:
	LoggingHandler(Reactor*reactor,int fd);
	virtual ~LoggingHandler();


	int getHandle() override;
	void handleEvent(int fd, Event_Type type) override;

	void handleInput(int fd) override;
	void handleOutput(int fd) override;
	void handleTimeout(int fd) override;
	void handleClose(int fd, Event_Type type) override;
private:
	uint32_t fd_;
	SockStream stream_;
	Reactor*reactor_;
	//sock_straem stream;
};
