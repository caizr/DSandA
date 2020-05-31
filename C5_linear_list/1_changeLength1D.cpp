/* 改变一个一维数组的长度 
* void changeLengh1D(T* &a,int oldLength, int newLength)
*
*/
#include<iostream>
/* 我的做法 */
template<class T>
void changeLength1D_my(T* &a,int oldLength,int newLength){
    T* tmp=new T[newLength];
    //新数组与原数组长度比较
    if(oldLength>=newLength)
        return;
    for(int i=0;i<oldLength;++i){
        tmp[i]=a[i];
    }
    a=tmp;
    //这里犯了一个错误：tmp使用完之后需要删除分配的内存空间！！！
    delete[] tmp;

}
/* 书上的做法 */
template<class T>
void changeLength1D(T* &a,int oldLength, int newLength){
    //很有必要判断错误并抛出异常
    if(newLength<0)
        throw illegalParameterValue("new length must be>=0");
    T* temp = new T[newLength];
    //min函数判断最小
    int number=min(oldLength,newLength);
    //copy函数
    copy(a,a+min,temp);
    delete [] a;
    a=temp;
}
int main(){
    int *a1=new int[3];    
    a1[0]=9;
    a1[1]=2;
    a1[2]=3;
    changeLength1D_my<int>(a1,3,5);
    std::cout<<a1[0]<<a1[1]<<a1[2]<<a1[3]<<a1[4]<<std::endl;
    
    return 0;
}