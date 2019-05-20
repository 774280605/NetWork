#pragma once

typedef unsigned int Event_Type;

enum
{
	READ_EVENT = 0x01,
	ACCEPT_EVENT = 0x02,
	WRITE_EVENT = 0x04,
	TIMEOUT_EVENT = 0x08,
	SIGNAL_EVENT = 0x10,
	CLOSE_EVENT = 0x20,

};
