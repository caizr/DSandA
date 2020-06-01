#include<iostream>
#include<sstream>
using namespace std;
int main(){
    ostringstream s;
    s<<"hello"<<endl;
    cout<<s.str();
    return 0;
}