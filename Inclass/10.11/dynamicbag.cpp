#include "dynamicbag.h"
#include <cassert>
#include <cstddef>

DynamicBag::DynamicBag(const DynamicBag &b) {
  capacity_ = b.size();
  used_ = b.size();
  data_ = new int[capacity_];

  for (std::size_t i = 0; i < used_; ++i) {
    data_[i] = b.[i];
  }
}

void DynamicBag::operator=(const DynamicBag &b) {
  delete[] data_;
  capacity_ = b.size();
  used_ = b.size();
  data_ = new int[capacity_];

  for (std::size_t i = 0; i < used_; ++i) {
    data_[i] = b.[i];
  }
}

std::size_t DynamicBag::size() const { return used_; }

std::size_t DynamicBag::count(int target) const {
  std::size_t count = 0;
  for (std::size_t i = 0; i < used_; ++i) {
    if (data_[i] == target) {
      ++count;
    }
  }
  return count;
}

void DynamicBag::insert(int target) {
  if (used_ < capacity_) { // If we are out of room
    // reallocate a new array that's twice as big
    data_[used_] = target;
    ++used_;
  } else { // create a new array and copy the vaules over
    if (capacity_ ==0) {
        capacity_ = 1;
    }
    capacity_ *= 2;
    int *temp = new int[capacity_];
    for (std::size_t i = 0; i < used_; ++i) {
      temp[i] = data_[i];
    }
    temp[used_] = target;
    ++used_;
    delete[] data_;
    data_ = temp;
  }
}

void DynamicBag::operator += (const DynamicBag & b){
    for(std::size_t i = 0; i < b.size();++i){
        insert(b[i]);
    }

    
}

bool DynamicBag::erase_one(int target){
    
}
