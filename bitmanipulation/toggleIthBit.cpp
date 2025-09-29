#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,ith;
    cin>>n>>ith;
    int mask=(1<<ith);
    int t;
    cin>>t;
    while(t--){
        n=n^mask;
        cout<<n<<endl;
    }

    return 0;
}