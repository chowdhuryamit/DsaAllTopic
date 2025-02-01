#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],vector<vector<int>>&ans,vector<int>&subSet,int start){
    for(int i=start;i<3;i++){
        subSet.push_back(arr[i]);
        ans.push_back(subSet);
        solve(arr,ans,subSet,i+1);
        subSet.pop_back();
    }
}
int main(){
    int arr[]={2,4,6};
    vector<vector<int>>ans;
    vector<int>subSet;
    int start=0;
    solve(arr,ans,subSet,start);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }


    return 0;
}