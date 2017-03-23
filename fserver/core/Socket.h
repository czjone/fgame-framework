//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_SOCKET_H
#define FSERVER_SOCKET_H

#include <core/fsys.h>
#include <core/Event.h>
#include <core/Buffer.h>
#include <string>
#include <queue>

class Socket : EventDispather {

public:
    class Event : public ::Event{
        friend class Socket;
    private:
        Event(EventDispather::EventKey key);
    public:
        static Event OnError;

        static Event OnRecived;

        static Event OnConnected;

        static Event OnClosed;

        static Event OnDisconnected;
    };

public:
    /**
     * 初始一个网络对象
     * @param host
     * @param port
     * @return
     */
    Socket(const char *host, Int32 port);

    virtual ~Socket();

    /**
     * 启动网络通信
     */
    void Star();

    void Close();

    void Send(const unsigned char * bytes);

    void Read(unsigned char* buffer,int len);

    int GetAvailable();

private:
    /**
     * 当前的session 是否可用
     * @return
     */
    Boolean  aliveSession();

private:
    std::string mHost;
    Int32 mPort;
    Int32 mSessionId;
    Buffer sendBuffer;
};


#endif //FSERVER_SOCKET_H
