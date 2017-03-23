//
// Created by solyess on 21/03/2017.
//

#include "Socket.h"

#	include <sys/types.h>
#	include <sys/socket.h>
#	include <netinet/in.h>
#	include <arpa/inet.h>
#	include <signal.h>
#	include <sys/ioctl.h>

static Event Socket::Event::OnError(1);

static Event Socket::Event::OnRecived(2);

static Event Socket::Event::OnConnected(3);

static Event Socket::Event::OnClosed(4);

static Event Socket::Event::OnDisconnected(5);

Socket::Socket(const char *host, Int32 port):
mHost(host),
mPort(port),
mSessionId(0)
{

}

Socket::~Socket() {
    this->Close();
}

void Socket::Star() {
    struct sockaddr_in sock_add;
    struct sockaddr_in server_addr;
    auto sessionId = this->mSessionId = socket(AF_INET, SOCK_STREAM, 0);
    if(sessionId < 0 ) {
        this->Dispatch(Socket::Event::OnError);
    }else{
        this->Dispatch(Socket::Event::OnConnected);
    }
}

void Socket::Close() {
    if(this->aliveSession()){
        shutdown(this->mSessionId, SHUT_RDWR);
    }

    this->Dispatch(Socket::Event::OnClosed);
}


void Socket::Send(const unsigned char *bytes) {
    (this-> sendBuffer) << bytes;
}

void Socket::Read(unsigned char *buffer, int len) {
    Buffer buf((const Byte*)buffer);

}

int Socket::GetAvailable() {

}

Boolean Socket::aliveSession(){

}

