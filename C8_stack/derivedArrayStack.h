/* 链表的数组描述
*
*/
#ifndef _DERIVEDARRAYSTACK
#define _DERIVEDARRAYSTACK
#include"stack.h"
template<class T>
class derivedArrayStack:public stack<T>{
    public:
        derivedArrayStack
        ~derivedArrayStack();
    private:
        T* data;
        int stackSize;
        int capacity;
};
#endif
