#pragma once
#include"EventHandler.h"
#include"Reactor.h"
#include"LFThreadPool.h"
class LFLoggingHandler:public EventHandler
{
public:
	LFLoggingHandler(Reactor*reactor,LFThreadPool*lfThreadPool,EventHandler*handler);
	virtual ~LFLoggingHandler();


	int handleInput(int fd) override;
	void handleOutput(int fd) override;
	void handleTimeout(int fd) override;
	void handleClose(int fd, Event_Type type) override;
	int getHandle() override;
	void handleEvent(int fd, Event_Type type) override;


private:
	Reactor*reactor_;
	LFThreadPool*lfThreadPool_;
	EventHandler* concreteEventHandler_;
};
