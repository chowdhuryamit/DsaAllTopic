#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int start,int mid,int end){
    vector<int>v;
    int i=start,j=mid+1;
    while(i<=mid &&j<=end){
        if(arr[i]<=arr[j]){
            v.push_back(arr[i]);
            i++;
        }
        else{
            v.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        v.push_back(arr[i]);
        i++;
    }
    while (j<=end)
    {
        v.push_back(arr[j]);
        j++;
    }
    for ( i = 0; i < v.size(); i++)
    {
        arr[start]=v[i];
        //cout<<v[i]<<" ";
        start++;
    }
    //cout<<endl;
}

void mergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int main(){
    int arr[]={72,34,90,23,56,87,34,12,74,0};
    int n=10;
    mergeSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<" ";
    }
    
}