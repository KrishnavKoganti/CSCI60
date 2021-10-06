#ifndef ATM_H  //if not defined, matching endif at the end
#define ATM_H  //then define

#include <iostream>
#include "bankaccount.h"
#include "bankaccount.cpp"

class ATM{
 
    private:
        int twenties_;
        int tens_;

    public:

    //Pre:  none
    //Post:  Set twenties and thens to 0
    ATM();

    //Pre: twenties and tens >= 0
    //Post: set twenties_ = twenties and tens_ = tens
    ATM(int twenties, int tens);
    
    //Pre: none 
    //Post: returns twenties_; 
    int twenties(){ return twenties_;}

    //Pre: none
    //Post: returns tens_
    int tens(){return tens_;}
    //Pre: amount%10 ==0 and b.get_balance() - amount >=0
    //Post: returns a b with the new balance. Also prints
    //the amount of 10s and 20s given
    BankAccount get_cash(int amount, BankAccount b);

    //pre:none
    //post: Transfer all bills from rhs to the called on atm
    void operator +=(ATM& rhs);

    //Pre:none
    //Post: Adds 10s and 20s to the machine
    void restock(int new20s, int new10s);

};
//pre: 2 ATM classes
//Post: Compares the 10s and 20s 
//if they are the same return true
//if else return false
bool operator ==(ATM lhs, ATM rhs);

//Pre:none
//Post: prints out the info
std::ostream& operator <<(std::ostream& out, ATM a);






#endif