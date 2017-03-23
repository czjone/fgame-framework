#ifndef __FISH_SERVER
#define __FISH_SERVER 1

#include <functional>
#include <core/fsys.h>
#include <Server/HandlerFilter.h>
#include <Message/Message.h>
#include <core/Event.h>

class Server : public EventDispather {

    typedef Int32 Error;
    typedef std::function<void(MsgData *)> ServerRecvHandler;
    typedef std::function<void(Error, MsgData *)> ServerErrorHandler;
public:
    class Event : public ::Event {
    public:
        Event(EventDispather::EventKey key);

    public:
        static Event OnError;

        static Event OnRecived;

        static Event OnConnected;

        static Event OnClosed;

        static Event OnDisconnected;
    };

public:

    enum Type {
        TCP = 0,
        HTTP = 1,
    };

public:
    void Init(const char *host, Int32 port);

    void Run();
};

class ServerNodeManager {

    class Config;

public:

    typedef std::function<int(Server &)> Handler;

private:

    ServerNodeManager();

public:

    ~ServerNodeManager();

    static Int32 Register(Server *server);

    static Int32 Register(Server *server, int serverid);

    static void UnRegister(Server *server);

    static void UnRegister(int serverId);

    static Server &Star(const char *host, Int32 port, Server::Type type, Handler onStaredCallback);

    static Server &Star(const char *host, Int32 port, Server::Type type, HandlerFilter &filter);

    static Server &Star(Config &cfg);

public:
    class Config {

        DEFINE_PROPERTY(const char* ,host);

        DEFINE_PROPERTY(Int32 ,port);

        DEFINE_PROPERTY(Server::Type ,type);

        DEFINE_PROPERTY(HandlerFilter& ,filter);
    };
};


#endif // end __FISH_SERVER