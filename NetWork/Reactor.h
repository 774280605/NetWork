#pragma once
#include "EventHandler.h"
#include "ReactorImpl.h"

class Reactor
{
public:
	Reactor();
	virtual ~Reactor();

	void register_handle(EventHandler*handler,Event_Type type);
	void register_handle(int fd, EventHandler*handler, Event_Type type);

	void remove_handle(EventHandler*handler, Event_Type type);
	void remove_handle(int fd, Event_Type type);
	void handle_events();

private:
	ReactorImpl* impl_;

};
