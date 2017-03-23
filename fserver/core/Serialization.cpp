#include "Serialization.h"
#include <yaml-cpp/yaml.h>


Serialization::Serialization() : mBuffer(nullptr) {

}

Serialization::Serialization(Buffer *buffer) :
        mBuffer((Buffer *) buffer) {

}

virtual Serialization::~Serialization() {
    delete mBuffer;
    mBuffer = nullptr;
}

/************************************************************************************
 * Yaml 序列化
 ***********************************************************************************/

YamlSerialization::YamlSerialization(){

}

YamlSerialization::YamlSerialization(Buffer *buffer){

}

/**
 * 对象转换成Buffer
 */
void YamlSerialization::ToBuffer(){

}

/**
 * buff转换成对象
 * @return
 */
YamlSerialization& YamlSerialization::ToObject(){

}