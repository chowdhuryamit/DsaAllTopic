#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={72,34,90,23,56,87,34,12,74,0};
    int n=10;
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    
    }
    
}