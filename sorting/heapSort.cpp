#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
      int arr[100];
      int size;

      heap(){
        size=0;
        arr[size]=-1;
      }

      void insert(int data){
        size=size+1;
        arr[size]=data;
        int index=size;
        while (index>1)
        {
            int parentIndex=index/2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index=parentIndex;
            }
            else{
                return;
            }
        }
      }

      void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
      }

      void deleteFromHeap(){
        if(size==0){
            cout<<"heap empty"<<endl;
            return;
        }
        else{
            arr[1]=arr[size];
            size--;
            int i=1;
            while (i<size)
            {
                int leftChild=(2*i);
                int rightChild=(2*i)+1;
                int largestIndex=i;
                if(leftChild<=size && arr[largestIndex]<arr[leftChild]){
                    largestIndex=leftChild;
                }
                if(rightChild<=size && arr[largestIndex]<arr[rightChild]){
                    largestIndex=rightChild;
                }
                if(largestIndex==i){
                  break;
                }
                else{
                    swap(arr[i],arr[largestIndex]);
                    i=largestIndex;
                }
            }
        }
      }
};

void heapify(int arr[],int n,int i){
    int largestIndex=i;
    int leftChild=(2*i);
    int rightChild=(2*i)+1;
    if(leftChild<=n && arr[leftChild]>arr[largestIndex]){
        largestIndex=leftChild;
    }
    if(rightChild<=n && arr[rightChild]>arr[largestIndex]){
        largestIndex=rightChild;
    }
    if(largestIndex==i){
        return;
    }
    else{
        swap(arr[i],arr[largestIndex]);
        heapify(arr,n,largestIndex);
    }
}

void buildHeap(int arr[],int n){
    for (int i = n/2; i >=1; i--)
    {
      heapify(arr,n,i);
    }
    
}

void heapSort(int arr[],int n){
    while (n>1)
    {
       swap(arr[1],arr[n]);
       n--;
       heapify(arr,n,1);
    }
    
}

int main(){
    // int arr[]={72,34,90,23,56,87,34,12,74,0};
    // int n=10;
    // priority_queue<int>pq;
    // for(int i=0;i<n;i++){
    //     pq.push(arr[i]);
    // }
    // int i=0;
    // while(!pq.empty()){
    //     arr[i]=pq.top();
    //     pq.pop();
    //     i++;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }


    // heap h;
    // h.insert(89);
    // h.insert(34);
    // h.insert(90);
    // h.insert(23);
    // h.insert(56);
    // h.insert(87);
    // h.print();
    // h.deleteFromHeap();
    // h.print();
    // h.deleteFromHeap();
    // h.print();

    int arr[]={-1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    buildHeap(arr,20); 
    int n=20;
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,n);
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}