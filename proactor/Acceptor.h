#pragma once
#include "CompletionHandler.h"
#include "Proactor.h"
#include "AsyncStream.h"
#include <MSWSock.h>
class Acceptor:public CompletionHandler
{
public:
	Acceptor(Proactor*proactor);
	virtual ~Acceptor();


	void handle_read(uintmax_t fd, const AsyncResult& result) override;
	void handle_write(uintmax_t fd, const AsyncResult& result) override;
	void handle_accept(uintmax_t fd, const AsyncResult& result) override;
	uintmax_t get_handle() override;

	void setup();
private:
	SOCKET accept_;
	AsyncStream* asyncStream_;
};
