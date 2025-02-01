#include<bits/stdc++.h>
using namespace std;

// void solve(string& s,char& target,int& index,int i){
//     if(i>=static_cast<int>(s.size())){
//         return;
//     }
//     if(s[i]==target){
//         index=i;
//     }
//     solve(s,target,index,i+1);
// }


int solve(string& s,char& target,int index){
   if(s[index]==target){
    return index;
   }
   if(index<0){
    return index;
   }
   return solve(s,target,index-1);
}

int main(){
    string s="amitchowdhuryamit";
    char target='z';
    int i=s.size()-1;
    cout<<solve(s,target,i)<<endl;



    return 0;
}