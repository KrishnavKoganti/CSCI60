#include "dUSet.h"
#include "dynamicbag.h"
#include <cstddef>

dUSet::dUSet() : DynamicBag(){};

dUSet::dUSet(DynamicBag &b) : DynamicBag(b) {

  for (std::size_t i = 0; i < size(); i++) {
    int count = this->count((*this)[i]);//finds the count of the number
    while (count > 1) {// checks if there is more than one
      this->erase_one((*this)[i]);//erases one of the values 
      count--;
    }
  }
}

void dUSet::insert(int target){
    if(count(target) == 0){//checks that the target is not in the set
        DynamicBag::insert(target);//inserts target
    }
}

