//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_HANDLERFILTER_H
#define FSERVER_HANDLERFILTER_H


#include <fsys.h>
#include <functional>
#include <queue>
#include <Message/Message.h>

class HandlerMessage;

typedef std::function<Boolean(HandlerMessage)> Handler;

class HandlerMessage : public MsgData {

public:
    HandlerMessage(Command cmd, Message &data);

    virtual  ~HandlerMessage();

    DEFINE_PROPERTY_READ_ONLY(Message,MsgData);
};

class HandlerFilter : public std::queue<Handler> {

public:
    struct Handler {
        Int32 cmd;
        Handler handler;
    };

public:

    void execute(HandlerMessage &hMsg);
};


#endif //FSERVER_HANDLERFILTER_H
