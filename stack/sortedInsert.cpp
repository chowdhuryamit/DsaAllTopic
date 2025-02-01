#include<bits/stdc++.h>
using namespace std;
void insertSort(stack<int>& st,int val){
    if(st.empty()||st.top()<=val){
        st.push(val);
        return;
    }
    int top=st.top();
    st.pop();
    insertSort(st,val);
    st.push(top);
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    insertSort(st,40);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0;
}