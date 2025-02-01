#include<bits/stdc++.h>
using namespace std;

bool solve(string& s,int left,int right){
    if(left>=right){
        return true;
    }
    if(s[left]!=s[right]){
        return false;
    }
    return solve(s,left+1,right-1);
}

int main(){
    string s="amitma";
    int left=0,right=s.size()-1;
    cout<<solve(s,left,right)<<endl;



    return 0;
}