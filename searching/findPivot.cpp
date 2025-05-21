#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={10,60,209,3};
    int left=0,right=3;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(mid+1<7 && arr[mid]>arr[mid+1]){
            cout<<mid<<endl;
            break;
        }
        else if(mid-1>=0 && arr[mid]<arr[mid-1]){
            cout<<mid-1<<endl;
            break;
        }
        else if(arr[mid]<arr[0]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }


    return 0;
}