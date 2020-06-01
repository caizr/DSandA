/* 使用基类实现arrayList类 */


#include<iostream>
#include "linearList.h"

using namespace std;

//类声明
template<class T> 
class arrayList: public linearList{
    public:
        //构造函数以及复制构造函数
        arrayList (size_t initialCapacity = 10);
        arrayList (const arrayList<T> &);
        //析构函数
        ~arrayList(){delete element;}
    protected:
        //检查 索引
        void checkIndex(size_t theIndex) const;
        //成员
        T *element;
        size_t arrayLength;
        size_t listsize;

};

//定义
template<class U>
arrayList<U>::arrayList(size_t initialCapacity=10){
    arrayLength=initialCapacity;
}