#include <bits/stdc++.h>
using namespace std;

int main() {

    int start,goal;
    cin>>start>>goal;
    int ans=start^goal;
    int count=0;
    while(ans){
        count++;
        ans=ans&(ans-1);
    }
    cout<<count<<endl;

    return 0;
}