#include<bits/stdc++.h>
using namespace std;
bool solve(stack<int>&st,int ele1){
    if(st.empty()){
        return true;
    }
    int ele2=st.top();
    if(ele1<=ele2){
        st.pop();
        bool ans=solve(st,ele2);
        st.push(ele2);
        return ans;
    }
    else{
        return false;
    }
}
int main(){
    stack<int>st;
    st.push(50);
    st.push(40);
    st.push(30);
    st.push(20);
    st.push(10);
    int ele1=INT_MIN;
    cout<<solve(st,ele1)<<endl;
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}