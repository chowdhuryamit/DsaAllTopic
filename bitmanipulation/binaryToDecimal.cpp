#include <bits/stdc++.h>
using namespace std;

int convertBinaryToDecimal(string bin){
    int ans=0;
    int pow=1;
    for(int i=bin.size()-1;i>=0;i--){
        if(bin[i]=='1'){
            ans+=pow;
        }
        pow*=2;
    }
    return ans;
}

int main() {

    string bin;
    cin>>bin;
    cout<<convertBinaryToDecimal(bin)<<endl;

    return 0;
}