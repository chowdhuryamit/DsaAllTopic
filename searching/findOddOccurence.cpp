#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,2,3,3,5,5,2,2,6,6,4};
    int left=0,right=10;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(left==right){
            cout<<left<<endl;
            break;
        }
        if(mid+1<=10 && arr[mid]!=arr[mid+1] && mid-1>=0 && arr[mid]!=arr[mid-1]){
           cout<<mid<<endl;
           break;
        }
        if(mid-1>=0 && arr[mid]==arr[mid-1]){
          if((mid-1)%2==0){
            left=mid+1;
          }
          else{
            right=mid-2;
          }
        }
        if(mid+1<=10 && arr[mid]==arr[mid+1]){
            if((mid)%2==0){
                left=mid+2;
            }
            else{
                right=mid-1;
            }
        }

    }
}