#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,3,-1,-3,5,3,6,7};
    deque<int>dq1,dq2;
    int k=3;
    vector<int>maxi,mini;
    for(int i=0;i<k;i++){
        while(!dq1.empty() && arr[dq1.back()]<=arr[i]){
            dq1.pop_back();
        }
        dq1.push_back(i);
    }
    maxi.push_back(arr[dq1.front()]);
    for(int i=k;i<8;i++){
        if(dq1.front()<i-k+1){
            dq1.pop_front();
        }
        while(!dq1.empty() && arr[dq1.back()]<=arr[i]){
            dq1.pop_back();
        }
        dq1.push_back(i);
        maxi.push_back(arr[dq1.front()]);
    }
    int sum=0;
    for (int i = 0; i < k; i++)
    {
        while(!dq2.empty() && arr[dq2.back()]>=arr[i]){
            dq2.pop_back();
        }
        dq2.push_back(i);
    }
    mini.push_back(arr[dq2.front()]);
    for (int i = k; i < 8; i++)
    {
        if(dq2.front()<i-k+1){
            dq2.pop_front();
        }
        while(!dq2.empty() && arr[dq2.back()]>=arr[i]){
            dq2.pop_back();
        }
        dq2.push_back(i);
        mini.push_back(arr[dq2.front()]);
    }
    
    
    for(int i=0;i<maxi.size();i++){
        sum+=maxi[i]+mini[i];
    }
    cout<<sum<<endl;


    return 0;
}