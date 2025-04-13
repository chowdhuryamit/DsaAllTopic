#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cin>>n>>i>>j;
    int a=((-1)<<(i+1));
    int b=~((-1)<<(j));
    int mask=a|b;
    n=(n&mask);
    cout<<n<<endl;


    return 0;
}