#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={72,34,90,23,56,87,34,12,74,0};
    int n=10;
    for(int  i=1;i<n;i++){
        int temp=arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}