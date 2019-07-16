#include "pch.h"
#include "Acceptor.h"
#include "AcceptorAsyncStream.h"
#include "Session.h"

Acceptor::Acceptor(Proactor* proactor):CompletionHandler(proactor){
}

Acceptor::~Acceptor(){
}

void Acceptor::handle_read(uintmax_t fd, const AsyncResult& result){
	
}

void Acceptor::handle_write(uintmax_t fd, const AsyncResult& result){
}

void Acceptor::handle_accept(uintmax_t fd, const AsyncResult& result){
	auto session = new Session(clientfd_, proactor_);
	asyncStream_->async_read(&clientfd_, sizeof(uintmax_t));
	servicesManager_.add(session);
}

uintmax_t Acceptor::get_handle(){
	return accept_;
}

void Acceptor::setup(){
	asyncStream_ = new AcceptorAsyncStream();

	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {

	}

	accept_ = socket(AF_INET, SOCK_STREAM, 0);
	if (accept_ == INVALID_SOCKET) {
		WSACleanup();
	}
	unsigned long blockiing = 1;
	ioctlsocket(accept_, FIONBIO, &blockiing);

	asyncStream_->open(accept_, this, proactor_);



	sockaddr_in service{};
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);

	if (bind(accept_, reinterpret_cast<sockaddr *>(& service), sizeof(service)) == SOCKET_ERROR) {
		closesocket(accept_);
		WSACleanup();
	}

	if (listen(accept_, 1) == SOCKET_ERROR) {
		closesocket(accept_);
		WSACleanup();
	}

	asyncStream_->async_read(&clientfd_,sizeof(uintmax_t));

}
