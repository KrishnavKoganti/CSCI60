#include "dynamicbag.h"
#include <cassert>
#include <cstddef>
#include <new>

DynamicBag::DynamicBag(){
  capacity_=0;
  used_ = 0;
  data_ = nullptr;//nullptr is our concept of pointing at nothing
}

//data_, capacity_, used_ must be initialized here
DynamicBag::DynamicBag(int arr[], std::size_t size){
  used_ = size;
  capacity_ = 2*size;
  data_ = new int[capacity_];

  for(std::size_t i = 0; i<used_; ++i){
    data_[i] = arr[i];
  }
}
DynamicBag::DynamicBag(const DynamicBag &b) {
  capacity_ = b.size();
  used_ = b.size();
  data_ = new int[capacity_];

  for (std::size_t i = 0; i < used_; ++i) {
    data_[i] = b[i];
  }
}

void DynamicBag::operator=(const DynamicBag &b) {
  delete[] data_;
  capacity_ = b.size();
  used_ = b.size();
  data_ = new int[capacity_];

  for (std::size_t i = 0; i < used_; ++i) {
    data_[i] = b[i];
  }
}

std::size_t DynamicBag::size() const { return used_; }

int DynamicBag::operator [](std::size_t pos) const{
  assert(pos<used_);
  return data_[pos];
}

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
  std::size_t marker = -1;
  for(std::size_t i= 0; i<used_ && marker==-1; ++i){
    if(data_[i] == target)
      marker = i;
  }
  if(marker==-1){
    return false;
  }
  
  for(std::size_t i = marker; i<used_-1; ++i){
    data_[i] = data_[i+1];
  }
  --used_;

  if((used_-1)<capacity_/4){
    capacity_/=2;
  }
  int* temp = new int[capacity_];
  for (std::size_t i = 0; i < used_; ++i) {
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
  return true;
}
std::size_t DynamicBag::erase(int target){
  std::size_t count = 0;
  while(erase_one(target)){
    ++count;
  }
  return count;
}


DynamicBag operator + (const DynamicBag & b1, const DynamicBag & b2){
  DynamicBag b;
  b+=b1;
  b+=b2;
  return b;
}

std::ostream& operator<<(std::ostream&  out, const DynamicBag& b){
  for(std::size_t i = 0; i<b.size(); ++i)
    out<<b[i]<<" ";
  return out;
}
