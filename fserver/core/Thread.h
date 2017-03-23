//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_THREAD_H
#define FSERVER_THREAD_H

#include <queue>
#include <string>
#include <core/fsys.h>

class Thread {

    typedef void* ThreadArg;

    typedef std::string ThreadName;

    typedef std::function<void(ThreadArg&)> ThreadHandler;

public:

    Thread(ThreadHandler handler,ThreadName threadName);

    void Star();

    void Stop();
};

class ThreadPool {

protected:

    ThreadPool();

    virtual  ~ThreadPool();

public :

    Int32 Join(Thread::ThreadHandler handler);

    void Delete(Int32 id);

    DEFINE_PROPERTY(Int32, Max);

};

#endif //FSERVER_THREAD_H
