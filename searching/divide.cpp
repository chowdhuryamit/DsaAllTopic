#include<bits/stdc++.h>
using namespace std;
int main(){
    int divisor,divident;
    cin>>divisor>>divident;
    int left=-divident,right=divident;
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(mid*divisor<=divident){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans;
}