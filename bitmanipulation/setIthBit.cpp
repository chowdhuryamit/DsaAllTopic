#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ith;
    cin>>n>>ith;
    int mask=(1<<ith);
    n=n|mask;
    cout<<n<<endl;
}