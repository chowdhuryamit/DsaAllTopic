#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int start=0,end=x;
        int ans=-1;
        long long int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            long long int pro=mid*mid;
            if(pro==x){
                return mid;
            }
            else if(pro<x){
               ans=mid;
               start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};