#include<bits/stdc++.h>
using namespace std;

int getFactorial(int n){
    //base case
    if (n==1)
    {
        return 1;
    }
    else
    {
        int ans=n*getFactorial(n-1);//recursive call
        return ans;
    }
}

void print(int n){
    // if(n==0){
    //     return;//----->base case
    // }
    // else{
    //     cout<<n<<endl;//----->processing
    //     print(n-1);//----recursive call
    // }
    if(n==0){
        return;
    }
    else{
        print(n-1);
        cout<<n<<endl;
    }

}

int pow(int n){
    if(n==0){
        return 1;
    }
    else{
        int ans=2*pow(n-1);
        return ans;
    }
}

int fib(int n){
    if(n==1||n==0){
        return n;
    }
    else{
        int ans=fib(n-1)+fib(n-2);
        return ans;
    }
}

int sum(int n){
    if(n==1){
        return 1;
    }
    else{
        int ans=n+sum(n-1);
        return ans;
    }
}


int main(){
    int n;
    cout<<"enter any number"<<endl;
    cin>>n;
    // int ans=getFactorial(n);
    // cout<<"Factorial of "<<n<<" is = "<<ans<<endl;


    cout<<sum(n);
}