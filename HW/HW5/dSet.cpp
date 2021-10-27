#include "dSet.h"
#include "dUSet.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sys/syslimits.h>

dSet::dSet() : dUSet(){};

dSet::dSet(DynamicBag &b) : dUSet() {
  DynamicBag temp;

  for (std::size_t i = 0; i < b.size();
       i++) { // uses the insert from dUSet to get rip of the duplicates
    dUSet::insert(b[i]);
  }
}

DynamicBag dSet::sort(DynamicBag &b) { // sort the bag
  int size = b.size();
  int a[size];
  for (std::size_t i = 0; i < size;
       i++) { // transfers the values from the bag to an array
    a[i] = b[i];
  }
  for (std::size_t i = 0; i < size; i++) { // sorts the array
    for (std::size_t j = 0; j < size; j++) {
      if (a[i] < a[j]) { // swaps the values
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  return DynamicBag(a, size);//returns a dynamic bag with the sorted values
}
void dSet::insert(int target){//inserts the target into the set
    for(std::size_t i = 0; i < size(); i++){
       if(target > (*this)[i]){
           this->insertAt((*this)[i], i+1);
       }
    }
}
