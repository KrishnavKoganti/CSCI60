#ifndef PICKUP_H
#define PICKUP_H

#include "automobile.h"

class Pickup:public Automobile{
  private:
    int capacity_;
    bool extendedCab_;

  public:
    Pickup();
    Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int capacity, bool extendedCab);

    //Getters
    int capacity(){return capacity_;}
    bool extendedCab(){return extendedCab_;}

    bool park(bool lot[], int size);
};
















#endif
