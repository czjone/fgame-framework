#include <Server/Server.h>

/**network events.*/
static Event Server::Event::OnError(1);
static Event Server::Event::OnRecived(2);
static Event Server::Event::OnConnected(3);
static Event Server::Event::OnClosed(4);
static Event Server::Event::OnDisconnected(5);

//Server::Event::Event(EventDispather::EventKey key) {
//
//}

void Server::Init(const char *host, Int32 port) {

}

void Server::Run() {

}
