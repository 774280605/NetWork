#pragma once

class Proactor
{
public:
	Proactor();
	virtual ~Proactor();

	void register_handle(int fd);
	void handle_events();



};
