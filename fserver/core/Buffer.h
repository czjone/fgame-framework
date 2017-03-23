//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_BUFFER_H
#define FSERVER_BUFFER_H

#include <core/fsys.h>

/**
 * Buffer
 */
class Buffer {
public:
    Buffer();

    Buffer(const Byte* buff);

    virtual ~Buffer();

public:
    /**
     * 写入缓冲区
     * @param bytes
     * @param len
     */
    State WriteBytes(const Byte * bytes,Int32 len);

    /**
     * 读取数据
     * @param bytes
     * @param len
     */
    State ReadBytes(Byte * bytes,Int32 len);

    /**
     * 写入数据
     * @param buff
     * @param bytes
     */
    void operator<<(Buffer &buff, Byte* bytes);

    /**
    * 写入数据
    * @param buff
    * @param bytes
    */
    void operator >>(Buffer &buff, Byte* bytes);

    /**
     * 读取数据
     * @param out
     * @return
     */
    template<typename T>
    State Read(T& out){
        Int32 size = sizeof(T);
        return this->ReadBytes(out,size);
    }

    /**
     * 写入数据
     * @param in
     * @return
     */
    template<typename T>
    State Write(T& in){
        Int32 size = sizeof(T);
        return this->WriteBytes((const Byte*)in,size);
    }


public:
    /**
     * 重置写游标
     * @param pos
     */
    void SetReadPos(Int32 pos);

    /**
     * 重置读取游标
     * @param Pos
     */
    void SetWritePos(Int32 Pos);

    /**
     * 重置读写游标
     * @param pos
     */
    void Reset(Int32 pos);

    /*******************************************************************************************/

    /**
     * 缓冲区
     */
    DEFINE_PROPERTY_READ_ONLY(Byte *, Buff);

    /**
     * 缓冲区容量,PS:如果设置的大小小于读游标,就重置读写游标.
     */
    DEFINE_PROPERTY_WITH_SETHANDLER(Int32 , Capability, [&](Int32 val){ this->Reset(this->getReadPos()); });

    /**
     * 读游标
     */
    DEFINE_PROPERTY_READ_ONLY(Int32 , ReadPos);

    /**
     * 写游标
     */
    DEFINE_PROPERTY_READ_ONLY(Int32 , WritePos);
};

#endif //FSERVER_BUFFER_H
