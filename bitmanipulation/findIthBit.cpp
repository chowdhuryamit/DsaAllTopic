#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ith;
    cin>>ith;
    ith-=1;
    int mask=(1<<ith);
    cout<<"mask "<<mask<<endl;
    if((n&mask)==0){
        cout<<"0"<<endl;
    }
    else{
        cout<<"1"<<endl;
    }
    
}