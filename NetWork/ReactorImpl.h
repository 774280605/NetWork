#pragma once
#include "EventHandler.h"



class ReactorImpl
{
public:
	ReactorImpl();
	virtual ~ReactorImpl();

	

	virtual void register_handle(EventHandler*handler, Event_Type type) = 0;
	virtual void register_handle(int fd, Event_Type type) = 0;

	virtual void remove_handle(EventHandler*handler, Event_Type type) = 0;
	virtual void remove_handle(int fd, Event_Type type) = 0;
	virtual  void handle_events()=0;
};
