#ifndef CHAIN_
#define CHAIN_
#include<iostream>
using namespace std;
template<class T>
struct chainNode{
    chainNode<T> *next;
    T element;
    chainNode<T>(const T& ele){this->element=ele;}
    //chainNode<T> *nex加const修饰符会怎么样?
    chainNode<T>(const T& ele,chainNode<T> *nex){element=ele; next=nex;}
};

template<class T>
class chain{
    public:
    //解析函数
        chain();
        chain(int);
        chain(const chain<T> &);
        void output(ostream& out) const;
    //析构函数
        ~chain();
    //private:
        chainNode<T> *firstNode;
        int listsize;


};
template<class T>
chain<T>::chain(){
    ;
}

template<class T>
chain<T>::chain(const chain<T> & theList){
    //判断是否为空链表
    if(theList.firstNode==NULL){
        firstNode=NULL;
        return ;
    }
    firstNode = new chainNode<T>(theList.firstNode->element);
    struct chainNode<T> *buf1=theList.firstNode->next;
    struct chainNode<T> *buf2=new chainNode<T>(buf1->element);
    firstNode->next=buf2;
    struct chainNode<T> *buf3=firstNode->next;
    while(buf1->next!=NULL){
        buf2=new chainNode<T>(buf1->next->element);
        buf3->next=buf2;
        buf1=buf1->next;
        buf3=buf3->next;
    }
    //最后几个另尾指针为NULL
    buf3->next=NULL;
    
}
//析构函数
template<class T>
chain<T>::~chain(){
    cout<<"~chain!"<<endl;
    chainNode<T> * toDelete=firstNode;
    while(toDelete->next != NULL){
        chainNode<T> * temp=toDelete->next;
        delete toDelete;
        toDelete = temp;
    }
}

//输出
template<class T>
void chain<T>::output(ostream& out) const
{// Put the list into the stream out.
   for (chainNode<T>* currentNode = firstNode;
                      currentNode != NULL;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}
#endif
