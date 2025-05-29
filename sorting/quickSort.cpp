#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int start,int end){
    int pivot=arr[start];
    int count=0;
    for (int i = start+1; i <=end; i++)
    {
        if(arr[i]<=pivot){
           count++;
        }
    }
    int changeIndex=start+count;
    swap(arr[start],arr[changeIndex]);
    int left=start,right=end;
    while(left<changeIndex && right>changeIndex){
        while(arr[left]<=pivot){
            left++;
        }
        while (arr[right]>pivot)
        {
            right--;
        }
        if(left<changeIndex && right>changeIndex){
            swap(arr[left++],arr[right--]);
        }
    }
    return changeIndex;
    
}
void quickSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int p=solve(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}
int main(){
    int arr[]={72,34,90,23,56,87,34,12,74,0};
    int n=10;
    quickSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}