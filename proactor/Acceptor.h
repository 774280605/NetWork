#pragma once
#include "CompletionHandler.h"
#include "Proactor.h"
#include "AsyncStream.h"
#include <MSWSock.h>
#include "ServicesManager.h"
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
	SOCKET accept_{0};
	AsyncStreamBase* asyncStream_{nullptr};
	char buffer[1024]{0};
	uintmax_t clientfd_{};
	ServicesManager servicesManager_;
};
