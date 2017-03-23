//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_SERIALIZATION_H
#define FSERVER_SERIALIZATION_H

#include <core/fsys.h>
#include <core/buffer.h>

/**
 * 数据序列化
 */
template<typename T>
class Serialization {
public:
    Serialization();

    Serialization(Buffer *buffer);

    virtual ~Serialization();

    /**
     * 对象转换成Buffer
     */
    virtual void ToBuffer() = 0;

    /**
     * buff转换成对象
     * @return
     */
    virtual T &ToObject() = 0;

    /**
     * 数据缓存
     */
    DEFINE_PROPERTY_READ_ONLY(Buffer*, Buffer);
};


class YamlSerialization : public Serialization<YamlSerialization> {
public:

    YamlSerialization();

    YamlSerialization(Buffer *buffer);

    virtual ~YamlSerialization();

    /**
     * 对象转换成Buffer
     */
    virtual void ToBuffer();

    /**
     * buff转换成对象
     * @return
     */
    virtual YamlSerialization &ToObject();

};

class JsonSerialization : public Serialization<JsonSerialization> {

public:
    JsonSerialization();

    JsonSerialization(Buffer *buffer);

    virtual ~JsonSerialization();

    /**
     * 对象转换成Buffer
     */
    virtual void ToBuffer();

    /**
     * buff转换成对象
     * @return
     */
    virtual XmlSerialization &ToObject();
};

class ProtobufferSerialization : public Serialization<ProtobufferSerialization> {

public:
    ProtobufferSerialization();

    ProtobufferSerialization(Buffer *buffer);

    virtual ~ProtobufferSerialization();

    /**
     * 对象转换成Buffer
     */
    virtual void ToBuffer();

    /**
     * buff转换成对象
     * @return
     */
    virtual ProtobufferSerialization &ToObject();
};

class XmlSerialization : public Serialization<XmlSerialization> {

public:
    XmlSerialization();

    XmlSerialization(Buffer *buffer);

    virtual ~XmlSerialization();

    /**
     * 对象转换成Buffer
     */
    virtual void ToBuffer();

    /**
     * buff转换成对象
     * @return
     */
    virtual XmlSerialization &ToObject();
};

class ByteSerialization : public Serialization<ByteSerialization> {

public:
    ByteSerialization();

    ByteSerialization(Buffer *buffer);

    virtual ~ByteSerialization();

    /**
     * 对象转换成Buffer
     */
    virtual void ToBuffer();

    /**
     * buff转换成对象
     * @return
     */
    virtual ByteSerialization &ToObject();
};



#endif //FSERVER_SERIALIZATION_H
