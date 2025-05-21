#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=0,right=arr.size()-1;
        int ans;
        while(left<=right){
           int mid=left+(right-left)/2;
            if(arr[mid]<arr[mid+1]){ 
                left=mid+1;
            }
            else{
                ans=mid;
               right=mid-1;
            }
        }
        return ans;
    }
};