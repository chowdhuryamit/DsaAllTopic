#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char>st;
    string s="amitchowdhury";
    string ans="";
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }
    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    cout<<ans<<endl;
    
    return 0;
}