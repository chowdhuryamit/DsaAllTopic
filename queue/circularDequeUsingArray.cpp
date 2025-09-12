#include <bits/stdc++.h>
using namespace std;
class CircularDeque{
 public:
   int* arr;
   int n;
   int front;
   int rear;
   CircularDeque(int size){
    arr=new int[size];
    n=size;
    front=-1;
    rear=-1;
   }
   void pushFront(int val){
    if((front==0 && rear==n-1)||(front==rear+1)){
        cout<<"Deque overflow"<<endl;
    }
    else if(front ==-1 && rear==-1){
        front++;
        rear++;
        arr[front]=val;
    }
    else if(front==0){
        front=n-1;
        arr[front]=val;
    }
    else{
        front--;
        arr[front]=val;
    }
   }
   void pushBack(int val){
     if((front==0 && rear==n-1)||(front=rear+1)){
        cout<<"queue overflow"<<endl;
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        arr[front]=val;
    }
    else if(rear==n-1){
        rear=0;
        arr[rear]=val;
    }
    else{
        rear++;
        arr[rear]=val;
    }
   }
   void popFront(){
     if(front==-1 && rear==-1){
        cout<<"queue underflow"<<endl;
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==n-1){
        front=0;
    }
    else{
        front++;
    }
   }
   void popBack(){
     //underflow,one element,circular nature,normal flow
     if(front==-1 && rear==-1){
        cout<<"Deque Underflow"<<endl;     
     }
     else if(front==rear){
        front=-1;
        rear=-1;
     }
     else if(rear==0){
        rear=n-1;
     }
     else{
        rear--;
     }
   }
};

int main() {

    

    return 0;
}