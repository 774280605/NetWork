#include "pch.h"
#include<WinSock2.h>
#include "SockStream.h"

SockStream::SockStream(){

}

SockStream::~SockStream(){
}

int SockStream::read(void* buffer, int len){
	int bytes = 0;
	bytes = recv(socket_,static_cast<char*>(buffer),len,0);
	return bytes;
}

int SockStream::write(void* buffer, int len){

	int bytes = 0;
	bytes = send(socket_,static_cast<char*>(buffer),len,0);
	return bytes;
}

int SockStream::read(){
	return readBuffer_.read(socket_,-1);
}

int SockStream::getLength(){
	return readBuffer_.getLength();
}

uint32_t SockStream::getSocket() const{
	return socket_;
}

void SockStream::setSocket(uint32_t socket){
	socket_ = socket;
}
