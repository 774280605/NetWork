#pragma once
#include "global.h"

class EventHandler
{
public:
	virtual int handleInput(int fd) =0;
	virtual void handleOutput(int fd) = 0;
	virtual void handleTimeout(int fd) = 0;
	virtual void handleClose(int fd, Event_Type type)=0;
	virtual int getHandle()=0;
	virtual void handleEvent(int fd,Event_Type type)=0;


};
