#include<bits/stdc++.h>
using namespace std;
void solve(queue<int>&q){
    if(q.empty()){
        return;
    }
    int x=q.front();
    q.pop();
    solve(q);
    q.push(x);
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    solve(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    // stack<int>st;
    // while(!q.empty()){
    //     st.push(q.front());
    //     q.pop();
    // }
    // while(!st.empty()){
    //     q.push(st.top());
    //     st.pop();
    // }
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }


    return 0;
}