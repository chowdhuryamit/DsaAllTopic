#include <bits/stdc++.h>
using namespace std;

class Queue{
  public:
   int* arr;
   int size;
   int front;
   int rear;
   Queue(int n){
    size=n;
    arr=new int[n];
    front=-1;
    rear=-1;
   }
   void push(int val){
    if(front==-1 && rear==-1){
        front++;
        rear++;
        arr[rear]=val;
    }
    else if(rear<size){
        rear++;
        arr[rear]=val;
    }
    else{
        cout<<"Queue Overflow"<<endl;
    }
   }
   void pop(){
     if(front==-1 && front==-1){
        cout<<"Queue Underflow"<<endl;
     }
     else if(front==rear){
        front=-1;
        rear=-1;
     }
     else{
        front++;
     }
   }
   int getSize(){
      if(front==-1 && rear==-1){
         return 0;
      }
      else{
        return rear+1;
      }
   }
   int getFront(){
     if(front==-1){
        cout<<"Queue is empty"<<endl;
        return -1;
     }
     else{
        return arr[front];
     }
   }
   bool isEmpty(){
    return front==-1 && rear==-1;
   }

};

int main() {

    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.getFront()<<endl;
    q.pop();
    cout<<q.getFront()<<endl;
    cout<<q.getSize()<<endl;
    q.pop();
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}