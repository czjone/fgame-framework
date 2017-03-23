//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_MESSAGE_H
#define FSERVER_MESSAGE_H

#include <core/fsys.h>
#include <core/Serialization.h>
#include <functional>
#include <vector>

#define SERIALIZATION ByteSerialization

typedef Serialization<SERIALIZATION> Message;
typedef Int32 Command;
typedef std::function<void(Message *)> MsgHandler;

/**
 * 消息对象
 */
class MsgData {
public:
    MsgData(Command cmd, Message &data);

    template<typename T>
    inline T* getObject(){
        T *t = new T(this->mData->getBuffer());
        return t;
    }

    DEFINE_PROPERTY_READ_ONLY(SERIALIZATION*, Data);
};

class MessageManager {

public:

    /**
     * 发送消息
     * @param mdt 消息数据对象
     */
    void SendMsg(MsgData &mdt);

    /**
     * 接收消息
     * @param cmd 接收的消息号
     * @param handler 收到消息后的处理函数
     */
    void RecvMsg(Command cmd, MsgHandler handler);

    /**
     * 等待消息(阻塞)
     * @param cmd
     * @param handler
     */
    void WaitMsg(Command cmd, MsgHandler handler);

    /**
     * 消息对象的容量
     */
    DEFINE_PROPERTY(Int32, MaxWaitNum);

    /**
     * 接收队列
     */
    DEFINE_PROPERTY_READ_ONLY(std::vector<MsgData>, RecvMsgQueue);

    /**
     * 发送队列
     */
    DEFINE_PROPERTY_READ_ONLY(std::vector<MsgData>, SendQueue);

};

MessageManager MsgMgr;

#endif //FSERVER_MESSAGE_H
