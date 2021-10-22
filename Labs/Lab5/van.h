#ifndef VAN_H
#define VAN_H

#include "automobile.h"

class Van:public Automobile{
  private:
    int seats_;
  public:
    Van();
    Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int seats);
    bool park(bool lot[], int size);
    //Getters
    int seats(){return seats_;}
    
};











#endif
