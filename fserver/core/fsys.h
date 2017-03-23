//
// Created by solyess on 21/03/2017.
//

#ifndef FSERVER_FSYS_H
#define FSERVER_FSYS_H

//types
typedef  int Int32;
typedef unsigned  UInt32;
typedef unsigned char Byte;
typedef unsigned short UInt16;
typedef bool Boolean;

//NS NAME
#define  FNS_NAME fsh

//define Macro
/**只能在类开的最后使用这个宏来定义属性,以免影响类有其它成员的访问修饰符的级别**/
#define DEFINE_PROPERTY(__TYPE__,__NAME__) \
private: __TYPE__ m##__NAME__; \
public : inline __TYPE__ get##__NAME__(void){return m##__NAME__;};\
public : inline __TYPE__ set##__NAME__(__TYPE__ val){ this->m##__NAME__ = val ; return m##__NAME__;}

/**只能在类开的最后使用这个宏来定义属性,以免影响类有其它成员的访问修饰符的级别**/
#define DEFINE_PROPERTY_WITH_SETHANDLER(__TYPE__,__NAME__,__ON_SET__HANDLER) \
private: __TYPE__ m##__NAME__; \
public : inline __TYPE__ get##__NAME__(void){return m##__NAME__;};\
public : inline __TYPE__ set##__NAME__(__TYPE__ val){ this->m##__NAME__ = val ; __ON_SET__HANDLER(val); return m##__NAME__;}

/**只能在类开的最后使用这个宏来定义属性,以免影响类有其它成员的访问修饰符的级别**/
#define DEFINE_PROPERTY_READ_ONLY(__TYPE__,__NAME__) \
private: __TYPE__ m##__NAME__; \
public : inline __TYPE__ get##__NAME__(void){return m##__NAME__;};\
protected : inline __TYPE__ set##__NAME__(__TYPE__ val){ this->m##__NAME__ = val ; return m##__NAME__;}

#define LOG()
#define ASSERT();

typedef enum _State : Int32 {
    FS_UNKNOW = -0xFFFFFE,
    FS_EOF = -1,
    FS_SUCCESS = 0,
} State;

#endif //FSERVER_FSYS_H
