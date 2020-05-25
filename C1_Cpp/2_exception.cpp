/* 异常 */
#include<iostream>

using namespace std;
//判断值是否为正数，如果为负数，抛出异常
int positive(int num){
    if (num>0)
        return 1;
    else if(num==0)
        return 0;
    else if(num<0){
        throw "negative!";
    }
    return -1;
}
int main(){
    int a=-1,b=0;
    try{positive(a);}
    catch(char *e){
        cout<<e<<endl;
    }
    //cout<<a/b<<endl;
    return 0;
}
