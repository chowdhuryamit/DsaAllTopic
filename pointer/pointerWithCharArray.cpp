#include<bits/stdc++.h>
using namespace std;
int main(){
    char arr[]="amitchowdhury";
    char* cptr=arr;
    cout<<cptr<<endl;//whole string will be printed from the starting cptr to end
    cout<<*cptr<<endl;
    cptr=cptr+1;
    cout<<*cptr<<endl;
    cptr=cptr+2;
    cout<<*cptr<<endl;
    cout<<*(cptr+3)<<endl;
    cout<<cptr<<endl;


    return 0;
}