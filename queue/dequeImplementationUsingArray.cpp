#include <bits/stdc++.h>
using namespace std;
class Deque{
  public:
   int* arr;
   int size;
   int front;
   int rear;
   Deque(int n){
    size=n;
    arr=new int[n];
    front=-1;
    rear=-1;
   }
   void pushFront(int val){
     if(front==0){
        cout<<"Deque Overflow"<<endl;
        return;
     }
     else if(front==-1 && rear==-1){
        front++;
        rear++;
        arr[front]=val;
     }
     else{
        front--;
        arr[front]=val;
     }
   }
   void pushRear(int val){
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
        cout<<"Deque Overflow"<<endl;
        return;
    }
   }
   void popFront(){
     if(front==-1 && front==-1){
        cout<<"Deque Underflow"<<endl;
     }
     else if(front==rear){
        front=-1;
        rear=-1;
     }
     else{
        front++;
     }
   }
   void popRear(){
     if(rear==-1 && front==-1){
        cout<<"Deque Underflow"<<endl;
     }
     else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        rear--;
    }
   }
   int getFront(){
        if(front==-1){
            cout<<"Deque is empty"<<endl;
        }
        else{
            return arr[front];
        }
   }
   int getRear(){
        if(rear==-1){
            cout<<"Deque is empty"<<endl;
        }
        else{
            return arr[rear];
        }
   }
};


int main() {

    Deque dq(5);
    dq.pushRear(10);
    dq.pushRear(20);
    cout<<dq.getFront();
    cout<<dq.getRear();
    dq.pushFront(5);
    dq.pushFront(1);
    cout<<dq.getFront();
    cout<<dq.getRear();
    dq.pushRear(90);
    dq.pushRear(9);
     cout<<dq.getFront();
    cout<<dq.getRear();

    return 0;
}