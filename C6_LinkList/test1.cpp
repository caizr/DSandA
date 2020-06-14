#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1{1,2,3,4};
    v1.push_back(5);
    cout<<v1[4]<<endl;
}