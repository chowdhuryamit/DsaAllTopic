#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
     stack<int>s1,s2;
    void enqueue(int x){
        s1.push(x);
    } 
    int dequeue(){
      if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(s2.empty()){
                return -1;
            }
            else{
                return s2.top();
                s2.pop();
            }
        }
        else{
            // return s2.top();
            // s2.pop();
            while(!s2.empty()){
                    cout<<s2.top();
                    s2.pop();
                }
        }
    }
};
int main(){
   Queue q;
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.dequeue();
   q.dequeue();

    return 0;
}