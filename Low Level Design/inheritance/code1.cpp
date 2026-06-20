#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class User{
    protected:
    int userId;
    string name;
    string phoneNumber;

    public:
    User(int userId,string name,string phoneNumber){
        this->userId=userId;
        this->name=name;
        this->phoneNumber=phoneNumber;
    }

    virtual void displayProfile()=0;
    virtual ~User(){};
};

class Rider:public User{
    private:
    string pickupLocation;
    string dropLocation;
    
    public:
    Rider(int userId,string name,string phoneNumber,string pickupLocation,string dropLocation):User(userId,name,phoneNumber){
        this->pickupLocation=pickupLocation;
        this->dropLocation=dropLocation;
    }
    void displayProfile() override{
        cout<<"  Rider's Profile  "<<endl;
        cout<<"Id: "<<userId<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"PhoneNumber: "<<phoneNumber<<endl;
    }
    void bookRide(){
       cout<<"Do you want to book a ride?"<<endl;
    }
};

class Driver:public User{
    private:
    string vehicleNumber;
    int Rating;

    public:
    Driver(int userId,string name,string phoneNumber,string vehicleNumber,int Rating):User(userId,name,phoneNumber){
        this->vehicleNumber=vehicleNumber;
        this->Rating=Rating;
    }

    void displayProfile() override{
        cout<<"  Drivers's Profile  "<<endl;
        cout<<"Id: "<<userId<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"PhoneNumber: "<<phoneNumber<<endl;
    }

    void acceptRide(){
        cout<<"Do you want to Accept the Ride?"<<endl;
    }
};


int main(){
    Rider *user1=new Rider(1,"Sourav","987654321","Hyderabad","Banglore");
    Driver *user2=new Driver(2,"Mohit","09887654332","AP0987656",4);
    user1->displayProfile();
    user1->bookRide();
    user2->displayProfile();
    user2->acceptRide();

    delete user1;
    delete user2;

    return 0;
}
