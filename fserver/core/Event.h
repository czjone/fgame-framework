//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_EVENT_H
#define FSERVER_EVENT_H


#include <core/fsys.h>
#include <functional>



class EventArgs{

};

class EventDispather {

public:
    typedef Int32 EventKey;

    typedef std::function<void(EventArgs&)> EventCallBack;

public:
    void AddEventListener(Event key,EventCallBack);

    void RemoveEventListener(Event key);

    void Dispatch(Event &evt);
};

class Event {
public:
    Event(EventDispather::EventKey key);
};


#endif //FSERVER_EVENT_H
