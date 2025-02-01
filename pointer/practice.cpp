#include<bits/stdc++.h>
using namespace std;

void solve(int* ptr){
    *ptr=(*ptr)*-1;
}
int main(){
    // int a=7;
    // int b=17;
    // int* ptr=&b;
    // *ptr=7;
    // cout<<a<<" "<<b<<endl;


    // int* ptr=0;
    // int a=10;
    // *ptr=a;
    // cout<<*ptr<<endl;


    // char ch='a';
    // char* ptr=&ch;
    // ch++;
    // cout<<*ptr<<endl;


    // int a=4;
    // int* ptr=&a;
    // ptr=ptr+1;
    // cout<<a<<" "<<*ptr<<endl;


    // int arr[]={4,5,6,7};
    // int* ptr=(arr+1);
    // cout<<*arr+9<<endl;


    // char arr[]="xyz";
    // char* ptr=&arr[0];
    // cout<<ptr<<endl;



    // char* ptr;
    // char str[]="abcdefgh";
    // ptr=str;
    // ptr+=5;
    // cout<<ptr<<endl;


    // int arr[]={1,2,3,4,5,6};
    // cout<<arr<<endl;
    // cout<<&arr[1]<<endl;
    // cout<<&arr[2]<<endl;


    int a=10;
    solve(&a);
    cout<<a<<endl;


    return 0;
}