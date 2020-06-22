/* 栈的定义 
*
*/
#ifndef _STACK
#define _STACK
template<class T>
class stack{
    public:
    //构造和析构函数
        virtual ~stack();
    //其他函数
        virtual bool empty() const =0;
        virtual int size() const =0;
        virtual const T& top() const =0;
        virtual void pop() =0;
        virtual void push(T) =0;
    /* 基于数组表示法
    private:
        T* data;
        int stackSize;
        int capacity;
    */
};

/************ 定义 ************/

#endif