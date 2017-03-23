#include "Ref.h"

Ref::Ref(void) :
        mRefCount(1) {

}

Ref::~Ref(void) {

}

void Ref::Retain() {
    this->mRefCount++;
}

void Ref::Release() {
    this->mRefCount--;
    if (this->mRefCount == 0) delete this;
}