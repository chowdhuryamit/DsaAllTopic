#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n=(n&(n-1));
    if(n==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}