/* 使用基类实现arrayList类 */
#ifndef arrayList_
#define arrayList_
#include "linearList.h"
#include<algorithm>

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

/* 没有写checkIndex，现在补充 */
template<class T> void arrayList<T>::checkIndex(size_t theIndex) const{
    if( theIndex<0 || theIndex>listsize){
        //抛出异常
        //书上的做法
        //std::ostringstream s;
        //s<<"index= "<<theIndex<<" size= "<<listsize;
        //throw illegalIndex("no");
        //我的做法
        std::cout<<"Index value error!"<<std::endl;
        throw "errorIndex";
    }
}



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
    //需要做一个index检查，之前没有考虑到这一点
    checkIndex(theIndex);
    return *(element+theIndex);
    //书上做法 return element[theIndex];
};
template<class T> int arrayList<T>::indexOf(const T& theElement) const{
    /* 书上做法：使用find函数 */
    //int a=(std::find(element,element+listsize,theElement)-element);
    //if(a == listsize)   return -1;
    //else    return a;
    for(int i=0;i<listsize;++i){
        if(theElement == *(element+i))
            return i;
    }
    return -1;
};
template<class T> void arrayList<T>::erase(int theIndex){
    //需要做一个index检查，之前没有考虑到这一点
    checkIndex(theIndex);
    //我理解的erase，应该是把该索引的空间都删除！
    std::copy(element+theIndex+1,element+listsize,element+theIndex);
    //delete element[listsize-1];
    --listsize;
    //书上接入了析构函数，我一开始以为是析构arrayList类，其实是析构element自身，因为element是T型
    //element[--listsize].~T();
};
template<class T> void arrayList<T>::insert(int theIndex, const T& theElement){
    //需要做一个index检查，之前没有考虑到这一点
    checkIndex(theIndex);
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