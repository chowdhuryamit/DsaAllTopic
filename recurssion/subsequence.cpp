#include<bits/stdc++.h>
using namespace std;

void subsequence(string s,string output,int index,int size){
   if(index==size){
    cout<<output<<endl;
    return;
   }
   subsequence(s,output+s[index],index+1,size);
   subsequence(s,output,index+1,size);
}

int main(){
    string s="amit";
    string output="";
    subsequence(s,output,0,4);



    return 0;
}