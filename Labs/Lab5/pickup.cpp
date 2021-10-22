#include "pickup.h"
#include "automobile.h"


Pickup::Pickup() : Automobile(){
  capacity_ = 0;
  extendedCab_ = false;
}

Pickup::Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int capacity, bool extendedCab) : Automobile(imake,imodel,iyear,iprice,istall){
  capacity_= capacity;
  extendedCab_ = extendedCab;
}

bool Pickup::park(bool lot[], int size){
  int spot=size;
  for(int i=0; i<size-1; i++){
      if(!lot[i] && !lot[i+1])
          spot = i;
  }
  if(spot>=size)//takes up 2 spaces
     return false;
  else{
      set_stall(spot);
      lot[spot] = true;
      lot[spot+1] = true;//takes up 2 spaces
      return true;
  }

}
