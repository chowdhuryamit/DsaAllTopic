#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={72,34,90,23,56,87,34,12,74,0};
    int n=10;
    for(int i=1;i<n;i++){
        int swaps=0;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaps++;
            }
        }
        if(swaps==0){
            break;
        }
    }
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    


    return 0;
}