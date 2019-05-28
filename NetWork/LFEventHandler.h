#pragma once
#include "EventHandler.h"
#include "LFThreadPool.h"
class LFEventHandler:public EventHandler
{
public:
	LFEventHandler(LFThreadPool*lfThreadPool,EventHandler*eventHandler);
	virtual  ~LFEventHandler();


	void handleInput(int fd) override;
	void handleOutput(int fd) override;
	void handleTimeout(int fd) override;
	void handleClose(int fd, Event_Type type) override;
	int getHandle() override;
	void handleEvent(int fd, Event_Type type) override;

	void startUp();
private:
	LFThreadPool* lfThreadPool_;
	EventHandler* concreteEventHandler_;
	
};
