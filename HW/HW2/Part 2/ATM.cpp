#include "ATM.h"
#include "bankaccount.h"
#include <iostream>


ATM::ATM(){
        twenties_ = 0;
        tens_ = 0;
}
ATM::ATM(int twenties, int tens){
        twenties_ = twenties;
        tens_ = tens;
}


BankAccount ATM::get_cash(int amount, BankAccount b){
    int temp = amount;
        if(amount % 10 == 0){
        if(b.get_balance()<amount){
            std::cout<<"Error: You do not have that much money"<<std::endl;
        }else{
            b.withdraw(amount);
            int twen = amount/20;
            int ten = (amount%20)/10;
            twenties_ -= twen;
            tens_-= ten;
            std::cout<<"Money Successfully Withdrawn. Change is : "<<std::endl;
            std::cout<<"10:"<<ten<<std::endl;
            std::cout<<"20:"<<twen<<std::endl;
        }
    }else{
        std::cout<<"Error: Please enter a multiple of 10"<<std::endl;
    }
    return b;
}

void ATM::operator +=(ATM& rhs){

    twenties_ = twenties_+rhs.twenties_;
    tens_ = tens_+ rhs.tens_;

}

void ATM::restock(int new20s, int new10s){
    twenties_ += new20s;
    tens_ += new10s;
}

bool operator== (ATM lhs, ATM rhs){
    if ((lhs.twenties() == rhs.twenties()) && (lhs.tens() == rhs.tens())){
        return true;
    }
    else
        return false;
}

std::ostream& operator <<(std::ostream& out, ATM a){
    out<<"Tens in ATM: "<<a.tens()<<std::endl;
    out<<"Twenties in ATM: "<<a.twenties()<<std::endl;
    return out;
}

