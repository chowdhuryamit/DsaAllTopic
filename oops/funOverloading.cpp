#include<bits/stdc++.h>
using namespace std;
class add{
    public:
     int sum(int x,int y){
        return x+y;
     }
     int sum(int x,int y,int z){
        return x+y+z;
     }
     double sum(double x,double y){
        return x+y;
     }
};
int main(){

    add a;
    cout<<a.sum(10,20)<<endl;
    cout<<a.sum(10,20,30)<<endl;
    cout<<a.sum(37.45,56.123)<<endl;


    return 0;
}