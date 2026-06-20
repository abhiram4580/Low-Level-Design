#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Payment{
  public:
  virtual void makePayment(double amount)=0;
  virtual ~Payment(){};
};


class CreditCard:public Payment{
   public:
   void makePayment(double amount) override{
     cout<<"Payment of "<<amount<<" has been made through [Credit Card]"<<endl;
   }
};

class UPI:public Payment{
    public:
    void makePayment(double amount)override{
        cout<<"Payment of "<<amount<<" has been made through [UPI]"<<endl;
    }
};

class NetBanking : public Payment{
    public:
    void makePayment(double amount)override{
        cout<<"Payment of "<<amount<<" has been made through [UPI]"<<endl;
    }
};

class WalletPayment :public Payment{
    public:
    void makePayment(double amount)override{
        cout<<"Payment of "<<amount<<" has been made through [Wallet]"<<endl;
    }
};

class PaymentService{
    private:
    Payment *payment;
    public:
    PaymentService(Payment *payment){
        this->payment=payment;
    }

    void PayAmount(double amount){
        payment->makePayment(amount);
    }

};



int main(){
    CreditCard c1;
    PaymentService p1(&c1);
    p1.PayAmount(10000);

    UPI u1;
    PaymentService p2(&u1);
    p2.PayAmount(100000);

    NetBanking n1;
    PaymentService p3(&n1);
    p3.PayAmount(100000);

    WalletPayment w1;
    PaymentService p4(&w1);
    p4.PayAmount(1000000);

    return 0;
}