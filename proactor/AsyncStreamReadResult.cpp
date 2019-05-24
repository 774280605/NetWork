#include "pch.h"
#include "AsyncStreamReadResult.h"

void AsyncStreamReadResult::complete(){
	handler->handle_read(handler->get_handle(), *this);
}
