#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    int speed;
    string brand;
     
    public:
    Car(const string &b,const int &s){
        speed=s;
        brand=b;
    }

    void accelerate(){
        speed+=10;
    }

    void brake(){
        speed=0;
    }

    void display(){
        cout<<"The "<<brand<<" is going at a speed of "<<speed<<"kmph"<<endl;
    }
};


int main(){
    Car c1("Ferrari",100);
    Car c2("Lamborgini",200);
    Car *c3=new Car("BMW",300);
    

    cout<<c3->speed<<" "<<c3->brand<<endl;

    c1.display();
    c2.display();

    c1.accelerate();
    c2.accelerate();

    c1.display();
    c2.display();

    c1.brake();
    c2.brake();

    c1.display();
    c2.display();

    return 0;
}