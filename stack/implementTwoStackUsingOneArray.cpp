#include <bits/stdc++.h>
using namespace std;

class Stack{
  public:
   int* arr;
   int size;
   int top1,top2;
    Stack(int n){
     size=n;
     arr=new int[n];
     top1=-1;
     top2=size;
    }
    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1]=x;
        }
        else{
            cout<<"Stack Overflow"<<endl;
            return;
        }
    }
    void push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2]=x;
        }
        else{
            cout<<"Stack Overflow"<<endl;
            return;
        }
    }
    void pop1(){
        if(top1>=0){
            top1--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
            return;
        }
    }
    void pop2(){
        if(top2<size){
            top2++;
        }
        else{
            cout<<"Stack Underflow"<<endl;
            return;
        }
    }
    int peek1(){
        if(top1>=0){
            return arr[top1];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    int peek2(){
        if(top2<size){
            return arr[top2];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty1(){
        return top1==-1;
    }
    bool isEmpty2(){
        return top2==size;
    }
    int size1(){
        return top1+1;
    }
    int size2(){
        return size-top2;
    }
};


int main() {

    

    return 0;
}