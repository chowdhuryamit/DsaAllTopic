#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={10,3,40,20,50,80,70};
    int left=0;
    int right=6;
    int target=70;
    bool found=false;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            found=true;
            cout<<mid<<endl;
            break;
        }
        if(arr[mid-1]==target){
            found=true;
            cout<<mid-1<<endl;
            break;
        }
        if(arr[mid+1]==target){
            found=true;
            cout<<mid+1<<endl;
            break;
        }
        if(arr[mid]<target){
            left=mid+2;
        }
        else{
            right=mid-2;
        }
    }
    cout<<found<<endl;

    return 0;
}