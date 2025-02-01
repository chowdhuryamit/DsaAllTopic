#include<bits/stdc++.h>
using namespace std;
int main(){
    // int num=10;//lvalue having memory
    // int *num1=&num;//rvalue doesnot have memory
    // cout<<num<<endl;
    // cout<<*num1<<endl;

    int n=10;
    int* ptr=&n;
    cout<<ptr<<endl;

    return 0;
}