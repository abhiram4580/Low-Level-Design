#include<iostream>
#include<bits/stdc++.h>
using namespace std;



enum class VehicleType{
    BIKE,
    CAR,
    TRUCK
};

string VehicleTypeToString(VehicleType vehicle){
    switch(vehicle){
        case VehicleType::BIKE: return "BIKE";
        case VehicleType::CAR: return "CAR";
        case VehicleType::TRUCK: return "TRUCK";
        default : return  "UNKNOWN";
    }
}

class ParkingTicket{
    private:
    int ticketId;
    string vehicleNumber;
    VehicleType vehicle;
    bool isPaid;

    public:
    ParkingTicket(int ticketId,string vehicleNumber,VehicleType vehicle){
        this->ticketId=ticketId;
        this->vehicleNumber=vehicleNumber;
        this->vehicle=vehicle;
        this->isPaid=false;
    }

    void markPaid(){
        isPaid=true;
    }

    void displayTicket(){
        cout<<"Vehicle Type: "<<VehicleTypeToString(vehicle)<<endl;
        cout<<"Vehicle Number: "<<vehicleNumber<<endl;
        cout<<"Paid Status: "<<(isPaid?"Paid":"Unpaid")<<endl;
    } 
};


int main(){
    ParkingTicket t1(101,"TS09AB234",VehicleType::CAR);
    ParkingTicket t2(102,"TS09BC567",VehicleType::BIKE);

    t1.markPaid();
    t2.markPaid();

    t1.displayTicket();
    t2.displayTicket();

    return 0;   
}