#include<bits/stdc++.h>
using namespace std;
void printPermutation(string s,int i){
    if(i==s.size()-1){
        cout<<s<<endl;
        return;
    }
     for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        printPermutation(s,i+1);
        swap(s[i],s[j]);
     }
}

void permuteStl(string s){
    sort(s.begin(),s.end());
    while (next_permutation(s.begin(),s.end()))
    {
        cout<<s<<endl;
    }
    
}
int main(){
    string s="abcd";
    int i=0;
    //printPermutation(s,i);
    cout<<s<<endl;
    permuteStl(s);

    return 0;
}