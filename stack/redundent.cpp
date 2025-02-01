#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="((1)*((3+6)))";
    stack<char>st;
    int redundent=0;
    int op=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'){
            st.push(s[i]);
        }
        else if (s[i]==')')
        {
            while (st.top()!='(')
            {
                char top=st.top();
                if(top=='+'||top=='-'||top=='/'||top=='*'){
                    op++;
                    st.pop();
                }
            }
            if(op==0){
                redundent++;
                st.pop();
            }
            else{
                op=0;
                st.pop();
            }
        }
    }
    cout<<redundent<<endl;


    return 0;
}