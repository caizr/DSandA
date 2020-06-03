这是学习Sartaj Sahni的数据结构、算法与应用的笔记、
C1: 模版函数;异常

C1 NOTICE:
        /* 动态分配内存 */
        1. 一位数组的分配
        2. 二维数组分配（两种情况）
            f(T** &x)和f(T** x)的差别
        3. 二维数组空间释放

c5: 线性表

C5 NOTICE:
        1. 模板函数默认参数的定义和声明
            template<class T> void f(T a=10);//declaration
            ...
            //注意定义的时候不能把默认值放到参数列表!
            template<class T> void f(T a){/* ... */}//definition
        2. 构造函数考虑不全，参考代码
        3. 自己使用了copy将部分元素左移，以达到删除目的
        4. checkIndex用来检测索引值的异常，并是为protected成员，每次涉及
           到使用Index的操作都应该先用checkIndex检查（例如get,erase)
        5. 使用find查找函数
        6. erase最后使用了析构： element[--listsize].~T();
        7. 插入函数没有做好，只能尾插，不能从中间插，我写的中间插会覆盖该索引
           值对应的元素
        8. 插入函数有一个很重要的细节，即每次插入，如果列表的长度不够，就x2，
           P101给出理论解释