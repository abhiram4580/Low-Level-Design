#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BankAccount{
    private:
    string accountNumber;
    string holderName;
    long long balance;

    public:
    
    BankAccount(string number,string hname,int bal){
        accountNumber=number;
        holderName=hname;
        if(bal<0){
            cout<<"Invalid Balance Entered. Setting Initial Balance to 0 !"<<endl;
            balance=0;
        }
        else{
            balance=bal;
        }
        
    }

    void Deposit(long long amount){
       if(amount<=0){
        cout<<"Please enter valid Amount!"<<endl;
        return ;
       }
       else{
         balance=balance+amount;
        cout<<"Money Deposited Successfully"<<endl;
        return ;
       }
    }

    void withdraw(long long amount){
        if(amount<=0){
            cout<<"Please enter a valid Amount !"<<endl;
        }
        if(balance<amount){
            cout<<"Insufficient Balance"<<endl;
            return ;
        }
        else{
            balance=balance-amount;
            cout<<"Please collect your cash"<<endl;
            return ;
        }
    }

    void DisplayAcc(){
        cout<<"Account Holder Name: "<<holderName<<endl;
        cout<<"Account Holder Number: "<<accountNumber<<endl;
        cout<<"Balance :"<<balance<<endl;
    }
};


int main(){
    BankAccount acc("ACC458","Abhiram",111100000);
    acc.Deposit(2000);
    acc.withdraw(1000000);
    acc.DisplayAcc();
}


/*
Missing validation for negative withdraw amount
Missing validation for zero withdraw amount
Constructor did not validate negative initial balance
Used INT_MIN to represent invalid balance
Treated initial balance 0 as invalid
Ternary operator precedence mistake with cout
Forgot return after invalid withdraw amount
Constructor parameter used int instead of long long
Inconsistent method naming: Deposit, withdraw, DisplayAcc
*/