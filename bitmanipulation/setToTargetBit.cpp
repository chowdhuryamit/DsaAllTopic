#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ith,target;
    cin>>n>>ith>>target;
    int mask=~(1<<ith);
    n=n&mask;
    if (target==0)
    {
        cout<<n<<endl;
    }
    else{
        mask=(1<<ith);
        n=n|mask;
        cout<<n<<endl;
    }
    


    return 0;
}