/* 使用基类实现arrayList类 */
#ifndef arrayList_
#define arrayList_
#include "linearList.h"


//类声明
template<class T> 
class arrayList: public linearList<T>{
    public:
        //构造函数以及复制构造函数
        arrayList (size_t initialCapacity = 10);
        arrayList (const arrayList<T> &);
        //析构函数
        ~arrayList(){delete element;}
        //成员函数
        bool empty() const;
        int size() const;
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        //void output(ostream& out) const;
        //自写的output
        void output() const;
        //其他方法
        int capacity() const {return arrayLength;}
    protected:
        //检查 索引
        void checkIndex(size_t theIndex) const;
        //成员
        T *element;
        size_t arrayLength;
        size_t listsize;

};

//定义构造，拷贝函数

/*
//该自写的构造函数考虑不全
template<class U>
arrayList<U>::arrayList(size_t initialCapacity){
    arrayLength=initialCapacity;
    
}
*/
/*********************书上的实现方式*********************/
template<class T>
arrayList<T>::arrayList(size_t initialCapacity){
    if(initialCapacity<1){
        ;/* 抛出异常*/
    }
    arrayLength=initialCapacity;
    // 错误 T *element=new T[initialCapacity];
    element=new T[initialCapacity];
    //需要初始化listsize
    listsize=0;
}

template<class U>
arrayList<U>::arrayList(const arrayList<U> &c){
    
    // element为指针，错误：element=c.element;
    arrayLength=c.arrayLength;
    listsize=c.listsize;
    //正确写法
    element=new U[arrayLength];
    std::copy(c.element,c.element+c.listsize,element);
}
//成员函数定义
template<class T> bool arrayList<T>::empty() const{
    if(listsize==0)
        return true;
    else
        return false;
}
template<class T> int arrayList<T>::size() const{
    return listsize;
};
template<class T> T& arrayList<T>::get(int theIndex) const{
    return *(element+theIndex);
};
template<class T> int arrayList<T>::indexOf(const T& theElement) const{
    for(int i=0;i<listsize;++i){
        if(theElement == *(element+i))
            return i;
    }
    return -1;
};
template<class T> void arrayList<T>::erase(int theIndex){
    //我理解的erase，应该是把该索引的空间都删除！
    std::copy(element+theIndex+1,element+listsize,element+theIndex);
    //delete element[listsize-1];
    --listsize;
};
template<class T> void arrayList<T>::insert(int theIndex, const T& theElement){
    *(element+theIndex)=theElement;
    ++listsize;
};
template<class T> void arrayList<T>::output() const{
    for(int i=0;i<listsize;++i){
        std::cout<<*(element+i)<<"->";
    }
    std::cout<<"end"<<std::endl;
}

#endif