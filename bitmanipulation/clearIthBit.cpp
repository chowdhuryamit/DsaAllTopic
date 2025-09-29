// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,ith;
//     cin>>n>>ith;

//     //left shift
//     // int mask=(1<<ith);
//     // n&mask?cout<<"setbit":cout<<"notsetbit";


//     //right shift

//     if((n>>ith)&1){
//         cout<<"setbit"<<endl;
//     }
//     else{
//         cout<<"notsetbit"<<endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,ith;
    cin>>n>>ith;
    int mask=~(1<<ith);
    n=n&mask;

    cout<<n<<endl;
    return 0;
}