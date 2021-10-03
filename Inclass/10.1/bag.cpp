#include "bag.h"

Bag::Bag(){
  size_=0;
  for(std::size_t i = 0; i<CAPACITY; ++i){
    data_[i] = 0;
  }
}

Bag::Bag(int arr[], std::size_t size){
  assert(size<CAPACITY);
  size_=size;
  for(std::size_t i = 0; i<CAPACITY; ++i){
    data_[i] = arr[i];
  }
}

std::size_t Bag::count(int target) const{
  std::size_t count = 0;
  for(std::size_t i=0; i< size_; ++i){
    if(data_[i]==target)
      ++count;
  }
  return count;
}

void Bag::insert(int target){
  assert(size() < CAPACITY);
  data_[size()] = target;
  ++size_;

}

// pre: size() + b.size() <= CAPACITY
// post: adds a copy of each element of b to this Bag
void operator += (const Bag & b);

// pre: none
// post: if target appears in this Bag, removes one copy of target and returns true
//       else returns false
bool erase_one(int target);

// pre: none
// post: if target appears in this Bag k times, removes all copies and returns k
//       else returns 0
std::size_t erase(int target);
