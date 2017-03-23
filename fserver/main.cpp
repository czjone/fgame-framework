#include <iostream>

#include <Server/Server.h>
#include <Server/HandlerFilter.h>

int main() {
    HandlerFilter filter;
    //server node.
    ServerNodeManager::Config cfg;
    cfg.sethost("192.168.1.10");
    cfg.setport(8080);
    cfg.settype(Server::Type::TCP);
    cfg.setfilter(filter);
    ServerNodeManager::Star(cfg);

    return 0;
}