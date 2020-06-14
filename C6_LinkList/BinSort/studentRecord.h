/* 箱子排序，定义studentRecord结构
*  包括学生的姓名和分数
*/
#ifndef _STUDENTRECORD
#define _STUDENTRECORD
#include "chain.h"

struct studentRecord{
    int score;
    std::string * name;      //注意这里使用指针
    
    //这里重载类型转换操作符int(), 这样就能完成+,/
    // <=和!=这些算术和关系操作符
    //从studentRecord到int类型的转换
    operator int() const{return score;}
    //输出
    /*
    std::ostream& operator<<(std::ostream& out,const studentRecord &x){
        std::out<<x.score<<' '<<*x.name<<std::end;
        return out;
    }
    */
};











#endif
