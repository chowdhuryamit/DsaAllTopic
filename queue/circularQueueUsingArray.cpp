#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
 public:
  int* arr;
  int size;
  int front;
  int rear;
  CircularQueue(int n){
    arr=new int[n];
    size=n;
    front=-1;
    rear=-1;
  }
  void push(int  val){
    //overflow,first element,circular nature,normal flow
    if((front==0 && rear==size-1)||(front=rear+1)){
        cout<<"queue overflow"<<endl;
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        arr[front]=val;
    }
    else if(rear==size-1){
        rear=0;
        arr[rear]=val;
    }
    else{
        rear++;
        arr[rear]=val;
    }
  }
  void pop(){
    //underflow,one element,circular nature,normal flow
    if(front==-1 && rear==-1){
        cout<<"queue underflow"<<endl;
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==size-1){
        front=0;
    }
    else{
        front++;
    }
  }
  int getFront(){
    if(front==-1){
        cout<<"queue is empty"<<endl;
    }
    else{
        return arr[front];
    }
  }
  int getSize(){
    if(front==-1 && rear==-1){
        return 0;
    }
    else if(front<=rear){
        return rear-front+1;
    }
    else{
        return size-(front-rear-1);
    }
  }
  bool isEmpty(){
    if(front==-1 && rear==-1){
        return true;
    }
    else{
        return false;
    }
  }
};

int main() {

    

    return 0;
}