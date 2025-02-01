#include<bits/stdc++.h>
using namespace std;

void solve(string& s,int left,int right){
    if(left>=right){
        return;
    }
    swap(s[left],s[right]);
    solve(s,left+1,right-1);
}

int main(){

    string s="adhiraj";
    int left=0;
    int right=s.size()-1;
    solve(s,left,right);
    cout<<s<<endl;


    return 0;
}