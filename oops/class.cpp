#include<bits/stdc++.h>
using namespace std;
class student{
    public:
     string name;
     int age;
     int roll;
     int nos;
    private: 
     float *cgpa;
     string gf;

    // student(){//--->default constructore which automatically include by compailer
    //     cout<<" constructore called"<<endl;
    // }

    //parameterrised constructure
    public:
    void setCgpa(float a){
        //another srcurity layer is added
        *this->cgpa=a;
    }
    void getCgpa(){
        cout<<*this->cgpa<<endl;;
    }
    student(string name,int age,int roll,int nos,float cgpa,string gf){
        cout<<"parametarised constructure called"<<endl;
        this->name=name;
        this->age=age;
        this->roll=roll;
        this->nos=nos;
        this->cgpa=new float(cgpa);
        this->gf=gf;
    }

    //copy constructure
    student(const student &srcObj){
        cout<<"copy constructure called"<<endl;
        this->name=srcObj.name;
        this->age=srcObj.age;
        this->roll=srcObj.roll;
        this->nos=srcObj.nos;
    }
     void study(){
        cout<<this->name<<" studying"<<endl;
     }
     void bunk(){
        cout<<this->name<<" bunking"<<endl;
     }
     void eat(){
        cout<<this->name<<" eating"<<endl;
     }
     ~student(){
        cout<<" destructure called"<<endl;
        delete this->cgpa;
     }
    private:
     void gfChatting(){
        cout<<this->name<<" chatting with gf"<<endl;
     } 
};
int main(){

    // student s1;
    // s1.name="amit chowdhury";
    // s1.age=23;
    // s1.roll=67;
    // s1.nos=5;
    
    // s1.study();

    // student s2;
    // s1.name="sudip karmakar";
    // s1.age=21;
    // s1.roll=25;
    // s1.nos=5;

    // s1.bunk();


    // student s1("amit chowdhury",23,67,5,9.1);
    // cout<<s1.name<<endl;
    // s1.name="sudip karmaker";
    // cout<<s1.name<<endl;
    // s1.study();

    // //student s2=s1;
    // student s2(s1);
    // s2.eat();

    // //dynamic allocation
    // student *s3=new student("bhola paul",21,100,6,8.5);
    // cout<<s3->name<<" "<<s3->age<<endl;
    // s3->bunk();
    // delete s3;


    student A("amit chowdhury",23,67,5,8.01,"ajshgvdas");
    cout<<A.name<<endl;
    //cout<<A.cgpa<<endl;//cant accessible because it is private
    A.getCgpa();
    A.setCgpa(8.5);
    A.getCgpa();
    return 0;
}