#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,val);
    st.push(topele);
}
void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int top=st.top();
    st.pop();
    insertAtBottom(st,top);
    //reverseStack(st);
}
int main(){
 stack<int>st;
 st.push(10);
 st.push(20);
 st.push(30);
 st.push(40);
 st.push(50);
 int size=st.size();
 for(int i=0;i<size;i++){
  reverseStack(st);
 }
 while (!st.empty())
 {
    cout<<st.top()<<" ";
    st.pop();
 }
 
    return 0;
}