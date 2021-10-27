#ifndef DUSET_H
#define DUSET_H
#include "dynamicbag.h"

class dUSet : public DynamicBag {

public:
  // constructor that takes in no arguments
  dUSet();
  // copies dynamicbag and removes all duplicates
  dUSet(DynamicBag &b);
  // inserts a target making sure it is not a duplicate
  void insert(int target);

  
};

#endif