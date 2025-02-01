#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
     int *arr;
     int size;
     int capacity;
    Heap(int capacity){
        this->arr=new int[capacity];
        this->size=0;
        this->capacity=capacity;
    } 
    void insert(int val){
        if(size>=capacity){
            cout<<"heap overflow"<<endl;
        }
        size++;
        int index=size;
        arr[index]=val;
        while (index>1)
        {
            int parentIndex=index/2;
            if(arr[parentIndex]<arr[index]){
                swap(arr[parentIndex],arr[index]);
                index=parentIndex;
            }
            else
            {
                break;
            }
            
        }
        
    }
    void printHeap(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
    int deleteFromHeap(){
        int ans=arr[1];
        arr[1]=arr[size];
        size--;
        int index=1;
        while (index<size)
        {
            int leftIndex=2*index;
            int rightIndex=(2*index)+1;
            int largestIndex=index;
            if(leftIndex<=size && arr[largestIndex]<arr[leftIndex]){
                largestIndex=leftIndex;
            }
            if(rightIndex<=size && arr[largestIndex]<arr[rightIndex]){
                largestIndex=rightIndex;
            }
            if(largestIndex==index){
                break;
            }
            else
            {
                swap(arr[index],arr[largestIndex]);
                index=largestIndex;
            }
            
        }
        return ans;
        
    }

};
void heapify(int arr[],int n,int index){
    int largestIndex=index;
    int leftIndex=2*index;
    int rightIndex=(2*index)+1;
    if(leftIndex<=n && arr[leftIndex]>arr[largestIndex]){
        largestIndex=leftIndex;
    }
    if(rightIndex<=n && arr[rightIndex]>arr[largestIndex]){
        largestIndex=rightIndex;
    }
    if(largestIndex!=index){
        swap(arr[index],arr[largestIndex]);
        heapify(arr,n,largestIndex);
    }
}
void buildHeap(int arr[],int n){
    for(int i=n/2;i>=1;i--){
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
    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);
    // h.printHeap();
    // cout<<endl;
    // cout<<h.deleteFromHeap()<<endl;
    //  h.printHeap();

   int arr[]={-1,5,79,30,24,6,3};
   buildHeap(arr,6);
   for (int i = 1; i <=6; i++)
   {
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   heapSort(arr,6);
   for (int i = 1; i <=6; i++)
   {
     cout<<arr[i]<<" ";
   }
   
   

    return 0;
}