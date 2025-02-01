#include<bits/stdc++.h>
using namespace std;
class Heap{
   public:
    int* arr;
    int capacity;
    int size;
    Heap(int capacity){
        this->capacity=capacity;
        this->size=0;
        this->arr=new int[capacity];
    }

    void printHeap(){
        for (int i = 1; i <=size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void insert(int val){
        if (size==capacity)
        {
            cout<<"overflow"<<endl;
        }
        size++;
        arr[size]=val;
        int index=size;
        while (index>1)
        {
            int parentIndex=index/2;
            if(arr[parentIndex]>arr[index]){
                swap(arr[parentIndex],arr[index]);
                index=parentIndex;
            }
            else{
                break;
            }
        }
    }

    void deleteHeap(){
        cout<<arr[1]<<endl;
        arr[1]=arr[size];
        int index=1;
        size--;
        // while(index<size){
        //     int leftIndex=2*index;
        //     int rightIndex=(2*index)+1;
        //     int minIndex=index;
        //     if(leftIndex<=size && arr[leftIndex]<arr[minIndex]){
        //         minIndex=leftIndex;
        //     }
        //     if(rightIndex<=size && arr[rightIndex]<arr[minIndex]){
        //         minIndex=rightIndex;
        //     }
        //     if(minIndex==index){
        //         break;
        //     }
        //     else{
        //         swap(arr[minIndex],arr[index]);
        //         index=minIndex;
        //     }
        // }
        heapify(arr,size,index);
    }
    void heapify(int arr[],int size,int index){
        int leftIndex=index*2;
        int rightIndex=(index*2)+1;
        int minIndex=index;
        if(leftIndex<=size && arr[leftIndex]<arr[minIndex]){
            minIndex=leftIndex;
        } 
        if(rightIndex<=size && arr[rightIndex]<arr[minIndex]){
            minIndex=rightIndex;
        } 
        if(minIndex!=index){
            swap(arr[minIndex],arr[index]);
            heapify(arr,size,minIndex);
        }
    }
};

void heapify(int arr[],int size,int index){
    int leftIndex=index*2;
        int rightIndex=(index*2)+1;
        int minIndex=index;
        if(leftIndex<=size && arr[leftIndex]<arr[minIndex]){
            minIndex=leftIndex;
        } 
        if(rightIndex<=size && arr[rightIndex]<arr[minIndex]){
            minIndex=rightIndex;
        } 
        if(minIndex!=index){
            swap(arr[minIndex],arr[index]);
            heapify(arr,size,minIndex);
        }
}
void buildHeap(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
}
void heapSort(int arr[],int n){
    while(n>1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}
int main(){
//    Heap h(10);
//    h.insert(20);
//    h.insert(10);
//    h.insert(3);
//    h.insert(100);
//    h.insert(1);
//    h.printHeap();
//    h.deleteHeap();
//    h.printHeap();

    int arr[]={0,90,20,40,30,60,10,70,80,50,100};
    buildHeap(arr,10);
    for (int i = 1; i <=10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    heapSort(arr,10);
    for (int i = 1; i <=10; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}