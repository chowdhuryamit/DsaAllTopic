#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=10;
    int* ptr=&a;
    int** ptr1=&ptr;

    cout<<*ptr<<endl;
    cout<<**ptr1<<endl;


    return 0;
}