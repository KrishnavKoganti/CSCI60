#include <iostream>

#include "ATM.h"
#include "ATM.cpp"
using namespace std;

int main()
{
    BankAccount bill;
    BankAccount bob(1991821, 100, 928040892, "Bob Smith");
    BankAccount rob(1994821, 100, 928040892, "Rob Smith");
    cout<<bob<<endl;
    ATM a1(20,10);
    ATM a2(5,20);

    
   bob=  a1.get_cash(70,  bob);
    cout<<bob<<endl;
    
    bool t = bob==bill;
    cout<< t<<endl;
    a1.restock(2, 3);
    a1+=a2;
    cout<<a1<<endl;


    return 0;
}
