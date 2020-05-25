/* 动态内存分配 
*  一维数组
*  一直某一个维度的二维数组的创建
*/
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;


int reach(int ** b){
  //  b[0][0]=2;

    b=new int*[3];
    b[0]=new int[2];
    //cout<<a[0][0]<<endl;
    return 0;
}

int Allocate2dArray(char ** &c,int columns,int rows);
int main(){
    //等价于 int *y=new int; *y=10;
    int *y=new int(10);
    cout<< *y<<endl;

    /* 一维数组内存分配 */
    //10个浮点数分配存储空间
    float *f=new float[10];
    //访问方式类似于数组
    cout<<f[20]<<endl;

    /* 删除分配的空间 */
    delete y;       // 删除变量
    delete []f;     // 删除一维变量


    /* 创建二维数据，其中列数已知，行数未知 */
    // n为未知数，根据计算或者用户输入得到
    // 已知列数为5，然而行数未知
    int n=10;
    char (*c)[5];
    c=new char[n][5];
    /*  列数未知，需要多次new分配   */
    char **x;
    Allocate2dArray(x,5,4);
    cout<<sizeof(x)<<endl;
}

/* 我的做法 ,注意 char ** &c应该视为 (char **) &c */
int Allocate2dArray(char ** &c,int columns,int rows){
    c=new char*[columns];               //应该是rows，不是columns
    for(int i=0;i<columns;++i){
        c[i]=new char[rows];
    }
    return 1;
}
/***************** 书上做法 **********************/
template<class T>
bool make2dArray(T ** &x,int Rows,int Columns){
    // 使用捕获异常
    try{
        // 创建行指针
        x= new T*[Rows];            //注意是rows，不是columns
        for(int i=0;i<Rows;++i){
            x[i]=new int [Columns];
        }
        return true;
    }
    catch(bad_alloc){return false;}
}
/****** 删除创建二维数组 *********/
template<class T>
void delete2dArray(T ** &x,int Rows){
    //删除行数组空间
    for(int i=0;i<Rows;++i){
        delete []x[i];
    }
    // 删除行指针
    delete []x;
    x=NULL;
}