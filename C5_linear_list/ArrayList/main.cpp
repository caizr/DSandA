/*
*
*
*
*/
#include<iostream>
#include<string>

#include"arrayList.h"

int main(){
    arrayList<int> a1 ;
    a1.insert(0,3);
   // std::cout<<a1->empty()<<std::endl;
    a1.insert(1,4);
    a1.insert(2,5);
    a1.insert(3,6);
    std::cout<<"before erase: ";
    a1.output();
    a1.erase(2);
    std::cout<<"after erase: ";
    a1.output();
    arrayList<int> a2(a1);

    arrayList<double> *d1=new arrayList<double>(100);
    std::cout<< "empty ?: " <<a2.empty()<<" indexOf(5): "<<a2.indexOf(5)
             <<" capacity: "<<a2.capacity()<<std::endl;
    return 0;
}