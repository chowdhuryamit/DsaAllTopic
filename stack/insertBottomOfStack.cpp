#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    solve(st,val);
    st.push(x);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    solve(st,19);
    solve(st,78);
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    

    return 0;
}