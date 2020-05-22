/* 模版函数 */
#include<iostream>

using namespace std;

template<typename T0,typename T1,typename T2>
T0 sum(T1 a,T2 b){
    return a+b;
}

int main(){
    cout<<sum<double,int,double>(1,2.5)<<endl;
    return 0;
}