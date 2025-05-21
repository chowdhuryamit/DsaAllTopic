#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(i%4==1){
            ans.push_back(1);
        }
        else if(i%4==2){
            ans.push_back(i+1);
        }
        else if(i%4==3){
            ans.push_back(0);
        }
        else{
            ans.push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" "<<endl;
    }


    return 0;
}