#include<bits/stdc++.h>
using namespace std;
void solve(queue<int>&q,int k,int s){
  if(k>s){
    return;
  }
  int x=k;
  stack<int>st;
  while (x--)
  {
    st.push(q.front());
    q.pop();
  }
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }
  s-=k;
  solve(q,k,s);
}
int main(){
    queue<int>q;
    q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // q.push(70);
    // q.push(80);
    // q.push(90);
    // q.push(100);
    // q.push(110);
    solve(q,3,1);
    int rem=1%3;
    while (rem--)
    {
        int x=q.front();
        q.pop();
        q.push(x);
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}