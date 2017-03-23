//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_REF_H
#define FSERVER_REF_H

#include <core/fsys.h>

/**
 * 托管对象
 */
class Ref {

protected:

    Ref();

public:

    virtual  ~Ref(void);

    void Retain();

    void Release();

    DEFINE_PROPERTY_READ_ONLY(Int32,RefCount);
};


#endif //FSERVER_REF_H
