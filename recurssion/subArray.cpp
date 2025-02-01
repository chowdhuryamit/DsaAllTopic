#include<bits/stdc++.h>
using namespace std;
void solve(string& s,int index,int size,string& output){
    if(index>=size){
        return;
    }
    output+=s[index];
    cout<<output<<endl;
    solve(s,index+1,size,output);

}
int main(){
    string s="amit";
    for (int i = 0; i <s.size(); i++)
    {
        string output="";
        solve(s,i,4,output);
    }
    


    return 0;
}