#include<iostream>
#include<bits/stdc++.h>
using namespace std;

enum class Coin{
    PENNY,
    NICKEL,
    DIME,
    QUARTER
};

int getCoinValue(Coin c){
    switch (c){
        case Coin::PENNY: return 1;
        case Coin::NICKEL: return 5;
        case Coin::DIME: return 10;
        case Coin::QUARTER: return 25;
        default: return 0;
    }
}

int main(){
    int total=getCoinValue(Coin::DIME)+getCoinValue(Coin::QUARTER);
    cout<<total<<endl;
}

