#include <bits/stdc++.h>
using namespace std;

string convertToBinary(int n){
    string res="";
    while(n!=1){
        if(n%2==0){
            res+='0';
        }
        else{
            res+='1';
        }
        n/=2;
    }
    res+=n+'0';
    reverse(res.begin(),res.end());
    return res;
}

int main() {

    int n;
    cin>>n;
    cout<<convertToBinary(n)<<endl;

    return 0;
}