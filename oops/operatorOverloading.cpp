#include<bits/stdc++.h>
using namespace std;
class Complex{
    public:
     int real;
     int img;
    Complex(int r=0,int i=0){
        this->real=r;
        this->img=i;
    }
    Complex operator+(const Complex &b){
        Complex temp;
        temp.real=this->real+b.real;
        temp.img=this->img+b.img;
        return temp;
    }
    Complex operator-(const Complex &b){
        Complex temp;
        temp.real=this->real-b.real;
        temp.img=this->img-b.img;
        return temp;
    }
    bool operator==(const Complex &b){
        return this->real==b.real||this->img==b.img;
    }
    void print(){
        cout<<this->real<<"+"<<this->img<<"i"<<endl;
    }
};
int main(){
    Complex c1(2,4);
    Complex c2(2,4);
    c1.print();
    c2.print();
    Complex c3=c1-c2;
    c3.print();
    bool a=c1==c2;
    cout<<a<<endl;
    return 0;
}