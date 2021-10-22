#include "van.h"
#include "automobile.h"

Van::Van() : Automobile(){
  seats_ = 7;
}

Van::Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int seats) : Automobile(imake,imodel,iyear,iprice,istall){
  seats_ = seats;
}


bool Van::park(bool lot[], int size){
    int spot=size;
    if(seats_>7){
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
    }else{
      for(int i=0; i<size; i++){
          if(!lot[i])
              spot = i;
      }
      if(spot>=size)
         return false;
      else{
          lot[spot] = true;
          set_stall(spot);
          return true;
      }
    }
    return false;
}
