#include<iostream>
#include"chain.h"

int main(){
    using namespace std;
    struct chainNode<int> a(10);
    struct chainNode<int> b(20);
    struct chainNode<int> c(30);
    a.next=&b;
    b.next=&c;
    chain<int> c1;
    c1.firstNode=&a;
    c1.listsize=10;

    

    chain<int> c2(c1);

    return 0;
}