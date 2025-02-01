#include<bits/stdc++.h>
using namespace std;
class vehicle{
   // private:
   //   string name;
   protected:
    string name;
    public:
     string model;
     int noOfTyer;

     vehicle(string name,string model,int noOfTyer){
        cout<<"constructure called from based class"<<endl;
        this->name=name;
        this->model=model;
        this->noOfTyer=noOfTyer;
     }
     string getName(){
      return this->name;
     }
     void startEngine(){
        cout<<"engine starting"<<this->name<<this->model<<endl;
     }
     void stopEngine(){
        cout<<"engine stopped"<<this->name<<this->model<<endl;
     }
};

class car:public vehicle{
   public:
    int noOfDoors;
    string transmission;

    car(string name,string model,int noOfTyer,int noOfDoors,string transmission):vehicle(name,model,noOfTyer){
        cout<<"constructure called from derived class"<<endl;
       this->noOfDoors=noOfDoors;
       this->transmission=transmission;
    }
    void startAc(){
        cout<<"start the ac"<<this->name<<this->model<<endl;
    }
};
int main(){
    car c1("fortuner","23x",4,4,"self");
    //cout<<c1.name<<endl;
   //  c1.startAc();
   //  c1.startEngine();
   cout<<c1.getName()<<endl;

    return 0;
}