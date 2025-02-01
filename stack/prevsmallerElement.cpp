#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={8,4,6,2,3};
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for (int i = 0; i < 5; i++)
    {
        while(st.top()>=arr[i]){
           st.pop();
        }
        ans.push_back(st.top());
        st.push(arr[i]);
    }
    //reverse(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    


    return 0;
}