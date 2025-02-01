#include<bits/stdc++.h>
using namespace std;
int solve(stack<int>&st,int p,int i){
   if(i==p){
    return st.top();
   }
   int x=st.top();
   st.pop();
   int ans=solve(st,p,i+1);
   st.push(x);
   return ans;
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int s=st.size();
    int p=s/2;
    int i=0;
    cout<<solve(st,p,i)<<endl;
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
}