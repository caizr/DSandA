#include<iostream>
#include"chain.h"

int main(){
    using namespace std;
    struct chainNode<int> a(10);
    struct chainNode<int> b(20);
    struct chainNode<int> c(30);
    struct chainNode<int> d(40);
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    chain<int> c1;
    c1.firstNode=&a;
    c1.listsize=10;
    
    

    chain<int> c2(c1);
    chain<int> c3(c2);
    c2.output(cout);
    cout<<endl;
    c.next=&d;
    d.next=NULL;
    c2.erase(0);
    c2.insert(1,50);
    c2.output(cout);
    cout<<endl;
    c1.output(cout);
    return 0;
}