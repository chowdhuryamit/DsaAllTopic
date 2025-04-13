#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ith;
    cin>>n>>ith;
    int mask=(1<<ith);
    mask=(~mask);
    cout<<(n&mask)<<endl;
}