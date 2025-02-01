#include<bits/stdc++.h>
using namespace std;

void solve(string& s,string& s1){
    int found=s.find(s1);
    if((int)found!=string::npos){
        s.erase(found,s1.size());
        solve(s,s1);
    }
    else{
        return;
    }

}

int main(){
    string s="abcjhdfabcfhjaabcbc";
    string s1="abc";
    solve(s,s1);

    cout<<s<<endl;



    return 0;
}