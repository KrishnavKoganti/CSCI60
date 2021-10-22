#include "automobile.h"
#include "pickup.h"
#include "van.h"
#include <iostream>

using namespace std;
int main(){


  Automobile a;
  int size = 6;
  bool carLot[size];

  for(int i = 0; i < size; i++){
    carLot[i] = false;
  }
  std::cout<<a.park(carLot, size)<<std::endl;

  //Problem 2 + 3

  Pickup b;
  //b.park(carLot, size);
  std::cout<<b.park(carLot, size)<<std::endl;

  Van c;
  Van d = Van("toyota", "highlander", 2019, 42000, 0, 20);
  // c.park(carLot,size);
  std::cout<<c.park(carLot, size)<<std::endl;
  std::cout<<d.park(carLot, size)<<std::endl;

  return 0;
}
