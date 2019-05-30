#pragma once
#include "EventHandler.h"
#include "LFThreadPool.h"
#include"Reactor.h"
class LFEventHandler:public EventHandler
{
public:
	LFEventHandler(Reactor*reactor,LFThreadPool*lfThreadPool,EventHandler*eventHandler);
	virtual  ~LFEventHandler();


	int handleInput(int fd) override;
	void handleOutput(int fd) override;
	void handleTimeout(int fd) override;
	void handleClose(int fd, Event_Type type) override;
	int getHandle() override;
	void handleEvent(int fd, Event_Type type) override;

	void startUp();
private:
	LFThreadPool* lfThreadPool_;
	Reactor* reactor_;
	EventHandler* concreteEventHandler_;
	
};
