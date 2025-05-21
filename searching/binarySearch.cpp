#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx=-1;
        int left=0,right=nums.size()-1;
        int mid=left+(right-left)/2;
        while(left<=right){
            mid=left+(right-left)/2;
            cout<<mid<<endl;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                idx=mid;
                break;
            }
        }
        return idx;
    }
};