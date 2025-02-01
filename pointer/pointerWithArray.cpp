#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={10,20,30,40,50};
    // cout<<arr<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<&arr<<endl;
    int* ptr=arr;
    ptr=ptr+1;
    cout<<*ptr<<endl;

    return 0;
}