#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int size=(1<<n);
    vector<vector<int>>ans;
    for(int i=0;i<size;i++){
      vector<int>subSet;
      int num=i;
      for(int j=0;j<n;j++){
        if(num&(1<<j)){
            subSet.push_back(arr[j]);
        }
      }
      ans.push_back(subSet);
    }

    for(int i=0;i<size;i++){
      for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
      }
      cout<<endl;
    }

    return 0;
}