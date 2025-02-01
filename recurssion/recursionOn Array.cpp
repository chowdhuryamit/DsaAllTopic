#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[],int n,int index){
    if(index==n){
        return;
    }
    else{
        cout<<arr[index]<<" ";
        index++;
        printArr(arr,n,index);
    }
}

bool searchInArr(int arr[],int n,int index,int target){
    if(index==n){
        return false;
    }
    if(arr[index]==target){
        return true;
    }
    else{
        index++;
        searchInArr(arr,n,index,target);
    }
}

void maxInArr(int arr[],int n,int index,int &maxi){
   if(index==n){
     return;
   }
   else{
    maxi=max(maxi,arr[index]);
    index++;
    maxInArr(arr,n,index,maxi);
   }
}

void minInArr(int arr[],int n,int index,int &mini){
   if(index==n){
     return;
   }
   else{
    mini=min(mini,arr[index]);
    index++;
    minInArr(arr,n,index,mini);
   }
}

void printOdd(int arr[],int n,int index){
    if(n==index){
        return;
    }
    else{
        if(arr[index]%2!=0){
            cout<<arr[index]<<" ";
        }
        index++;
        printOdd(arr,n,index);
    }
}

void printEven(int arr[],int n,int index,vector<int>&ans){
    if(n==index){
        return;
    }
    else{
        if(arr[index]%2==0){
            ans.push_back(arr[index]);
        }
        index++;
        printEven(arr,n,index,ans);
    }
}

int binarySearch(int arr[],int n,int start,int end,int target){
    if(start>end){
        return -1;
    }
    else{
        int mid=(start+end)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            start=mid+1;
            return binarySearch(arr,n,start,end,target);
        }
        else{
            end=mid-1;
            return binarySearch(arr,n,start,end,target);
        }
    }
}

void printDigit(int num){
    if(num==0){
        return;
    }
    else{
        int newNum=num/10;
        printDigit(newNum);
        int digit=num%10;
        cout<<digit<<" ";
    }
}

bool isSorted(int arr[],int size,int index){
    if(index==size-1){
        return true;
    }
    if(arr[index]>=arr[index+1]){
        return false;
    }
    return isSorted(arr,size,index+1);
}


int main(){
    // int arr[]={10,20,30,40,50,60};
    // int n=6;
    // int index=0;
    // int target=60;
    // int start=0;
    // int end=5;
    // int mini=INT_MAX;
    // vector<int>ans;
    //printArr(arr,n,index);
    //cout<<searchInArr(arr,n,index,target)<<endl;
    // minInArr(arr,n,index,mini);
    // cout<<mini<<endl;

    //printOdd(arr,n,index);
    // printEven(arr,n,index,ans);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    //cout<< binarySearch(arr,n,start,end,target);
    
    // long long num=2431564;
    // printDigit(num);
    int arr[]={10,15,25,35,877,95};
    int n=6;
    int index=0;
    cout<<isSorted(arr,n,index)<<endl;




    return 0;
}