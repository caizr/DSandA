#ifndef CHAIN_
#define CHAIN_

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
        chain();
        chain(int);
        chain(const chain<T> &);
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
    
}

#endif

