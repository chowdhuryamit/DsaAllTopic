#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,3,2,3,4,1,6,4,3};
    int maxi=*max_element(arr.begin(),arr.end());
    vector<int>temp(maxi+1,0);
    for(int i=0;i<arr.size();i++){
        temp[arr[i]]++;
    }
    for (int i = 1; i < temp.size(); i++)
    {
       temp[i]=temp[i]+temp[i-1];
    }
    vector<int>v(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--){
        int j=arr[i];
        temp[j]--;
        int k=temp[j];
        v[k]=j;
    }
    arr=v;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    

}