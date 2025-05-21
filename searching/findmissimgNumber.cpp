#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0,end=nums.size()-1;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]-mid==0){
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        if(ans==-1){
            ans=nums.size();
        }
        return ans;
    }
};