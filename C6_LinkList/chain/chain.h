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
    //构造函数
        chain();
        chain(int);
        chain(const chain<T> &);

    //析构函数
        ~chain();
    //
        void checkIndex(int) const;
         T& get(int theIndex) const;
         void output(ostream& out) const;
         //使用 T& element，如果调用的时候参数的const，就会出错！
         int indexOf(T element) const;
         //书上用的是 indexOf(const T& theElement) const;
         void erase(int theIndex);
         void insert(int theIndex,const T& theElement);
    //private:
        chainNode<T> *firstNode;
        int listsize;


};
template<class T>
chain<T>::chain(){
    ;
}

/**********************构造函数**********************/
template<class T>
chain<T>::chain(int capacity){
    firstNode=NULL;
    listsize=0;
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
/**********************析构函数**********************/
template<class T>
chain<T>::~chain(){
    cout<<"~chain!"<<endl;
    if(firstNode==NULL) return;
    chainNode<T> * toDelete=firstNode;
    while(toDelete->next != NULL){
        chainNode<T> * temp=toDelete->next;
        //delete toDelete;
        toDelete = temp;
    }
    //用这种方法的话，还需要删除最后一个节点
   // delete toDelete;
}
/* 书上的析构函数 */
/*  while(firstNode!=NULL){
        chainNode<T> *nextNode=firstNode->next;
        delete firstNode;
        firstNode=nextNode;
    }
*/
/**********************检查索引**********************/
template<class T>
void chain<T>::checkIndex(int theIndex) const{
    if(theIndex<0){
        cout<<"index invalid!"<<endl;
        // 抛出异常 ......
        return;
    }
}
/************************索引***********************/
template<class T>
T& chain<T>::get(int theIndex) const{
    if(theIndex<1){
        cout<<"Index invalid!"<<endl;
        throw("index invalid");
    }
    
    chainNode<T> *toGet=firstNode;
    while(theIndex!=0){
        toGet=toGet->next;
        --theIndex;
    }
    cout<<toGet->element<<endl;
    return toGet->element;
}
/* 书上的get函数 */
/*  
    // 使用checkIndex检查索引
    checkIndex(theIndex);
    //移动节点
    chainNode<T> *currentNode=firstNode;
    for(int i=0;i<theIndex;++i){
        currentNode=currentNode->next;
    }
    return currentNode->element;
*/
/**********************获取索引**********************/
template<class T>
int chain<T>::indexOf(T element) const{
    //索引变量
    int index=0;
    chainNode<T> * currentNode = firstNode;
    while(currentNode!=NULL){
        if(currentNode->element==element)
            return index;
        ++index;
        currentNode=currentNode->next;
    }
    return -1;
}
/* 书上的indexOf函数 */
/*  
int chain<T>::indexOf(const T& theElement) const{
    chainNode<T> * currentNode=firstNode;
    int index=0;
    while( currentNode != NULL &&
            currentNode->element != theElement){
        currentNode=currentNode->next;
        ++index;
    }
    if(currentNode==NULL)
        return -1;
    else 
        return index;
    
*/
/************************擦除***********************/
template<class T>
void chain<T>::erase(int theIndex){
    checkIndex(theIndex);
    //判断链表是否为空
    if(firstNode==NULL)
        return;
    /****擦除****/
    //索引为0的情况
    chainNode<T> *currentNode=firstNode;
    if(theIndex == 0){
        firstNode=currentNode->next;
        delete currentNode;
        return;
    }
    
    //移动到要擦除节点的上一个节点
    for(int i=0;i<theIndex-1;++i)
        currentNode=currentNode->next;
    chainNode<T> *toDelete=currentNode->next;
    currentNode->next=toDelete->next;
    delete toDelete;
    
}
/************************插入***********************/
template<class T>
void chain<T>::insert(int theIndex,const T& theElement){
    //检查索引
    checkIndex(theIndex);
    //0索引的插入
    chainNode<T> * toAdd(theElement);
    if(theIndex == 0){
        toAdd->next=firstNode->next;
        firstNode->next=toAdd;
        return ;
    }
    //非0索引的插入
    chainNode<T> *currentNode = firstNode;
    for(int i=0;i<theIndex;++i){
        currentNode=currentNode->next;
    }
    toAdd->next=currentNode->next;
    currentNode->next=toAdd;

}
/************************输出***********************/
template<class T>
void chain<T>::output(ostream& out) const
{// Put the list into the stream out.
   for (chainNode<T>* currentNode = firstNode;
                      currentNode != NULL;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}
#endif

