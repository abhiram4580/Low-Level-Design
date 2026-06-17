#include<iostream>
#include<bits/stdc++.h>
using namespace std;

enum class OrderStatus{
    PLACED,
    PREPARING,
    OUT_FOR_DELIVERY,
    DELIVERED,
    CANCELLED
};

string statusToString(OrderStatus status){
    switch (status){
        case OrderStatus::PLACED: return "PLACED";
        case OrderStatus::PREPARING: return "PREPARING";
        case OrderStatus::OUT_FOR_DELIVERY: return "OUT_FOR_DELIVERY";
        case OrderStatus::DELIVERED: return "DELIVERED";
        case OrderStatus::CANCELLED: return "CANCELLED";
        default : return "UNKNOWN";
    }
}


class Order{
    private:
    int orderId;
    string customerName;
    OrderStatus status;

    public:
    Order(int orderId,string customerName){
        this->orderId=orderId;
        this->customerName=customerName;
        this->status=OrderStatus::PLACED;
    }

    void updateStatus(OrderStatus newStatus){
       status=newStatus;
    }

    void displayOrder(){
         cout<<"Order ID: "<<orderId<<endl;
        cout<<"CustomerName: "<<customerName<<endl;
        cout<<"Order Status:"<<statusToString(status)<<endl;
    }
};

int main(){
    Order order1(1,"John");
    Order order2(2,"Pitt");

    order1.updateStatus(OrderStatus::DELIVERED);
    order2.updateStatus(OrderStatus::CANCELLED);

    order1.displayOrder();
    order2.displayOrder();


    
}
