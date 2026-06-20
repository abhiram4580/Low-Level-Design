#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RestaurantStaff {
protected:
    int staffId;
    string name;
    string phoneNumber;
    double salary;

public:
    RestaurantStaff(int staffId, string name, string phoneNumber, double salary) {
        this->staffId = staffId;
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->salary = salary;
    }

    virtual void displayDetails() = 0;
    virtual void calculateBonus() = 0;
    virtual void performDuty() = 0;

    virtual ~RestaurantStaff() {}
};

class Chef : public RestaurantStaff {
private:
    string specialization;
    int numberOfDishesPrepared;

public:
    Chef(int staffId, string name, string phoneNumber, double salary,
         string specialization, int numberOfDishesPrepared)
        : RestaurantStaff(staffId, name, phoneNumber, salary) {
        this->specialization = specialization;
        this->numberOfDishesPrepared = numberOfDishesPrepared;
    }

    void displayDetails() override {
        cout << "\nChef Details" << endl;
        cout << "ID: " << staffId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Salary: " << salary << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Dishes Prepared: " << numberOfDishesPrepared << endl;
    }

    void calculateBonus() override {
        cout << "Chef Bonus: " << numberOfDishesPrepared * 1000 << endl;
    }

    void performDuty() override {
        prepareFood();
    }

    void prepareFood() {
        cout << name << " is preparing food." << endl;
    }
};

class DeliveryPartner : public RestaurantStaff {
private:
    string vehicleNumber;
    int numberOfDeliveries;

public:
    DeliveryPartner(int staffId, string name, string phoneNumber, double salary,
                    string vehicleNumber, int numberOfDeliveries)
        : RestaurantStaff(staffId, name, phoneNumber, salary) {
        this->vehicleNumber = vehicleNumber;
        this->numberOfDeliveries = numberOfDeliveries;
    }

    void displayDetails() override {
        cout << "\nDelivery Partner Details" << endl;
        cout << "ID: " << staffId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Salary: " << salary << endl;
        cout << "Vehicle Number: " << vehicleNumber << endl;
        cout << "Deliveries Completed: " << numberOfDeliveries << endl;
    }

    void calculateBonus() override {
        cout << "Delivery Partner Bonus: " << numberOfDeliveries * 500 << endl;
    }

    void performDuty() override {
        deliverOrder();
    }

    void deliverOrder() {
        cout << name << " is delivering the order." << endl;
    }
};

int main() {
    vector<RestaurantStaff*> staff;

    RestaurantStaff* r1 = new Chef(1, "Rohan", "09876543211", 200000, "Pasta", 29);
    RestaurantStaff* r2 = new DeliveryPartner(2, "Aryan", "989898989", 200000, "AP0987654321", 20);

    staff.push_back(r1);
    staff.push_back(r2);

    for (RestaurantStaff* s : staff) {
        s->displayDetails();
        s->calculateBonus();
        s->performDuty();
    }

    for (RestaurantStaff* s : staff) {
        delete s;
    }

    return 0;
}