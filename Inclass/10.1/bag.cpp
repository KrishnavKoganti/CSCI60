#include "bag.h"
#include <cassert>

Bag::Bag() {
  size_ = 0;
  for (std::size_t i = 0; i < CAPACITY; ++i) {
    data_[i] = 0;
  }
}

Bag::Bag(int arr[], std::size_t size) {
  assert(size < CAPACITY);
  size_ = size;
  for (std::size_t i = 0; i < CAPACITY; ++i) {
    data_[i] = arr[i];
  }
}

std::size_t Bag::count(int target) const {
  std::size_t count = 0;
  for (std::size_t i = 0; i < size_; ++i) {
    if (data_[i] == target)
      ++count;
  }
  return count;
}

void Bag::insert(int target) {
  assert(size() < CAPACITY);
  data_[size()] = target;
  ++size_;
}

void Bag::operator+=(const Bag &b) {
  assert(size() + b.size() <= CAPACITY);
  std::size_t j = size_;
  for (std::size_t i = size_; i < b.size_; ++i) {
    data_[j] = b[i];
    ++j;
  }
  size_ = size_ + b.size_;
}

bool Bag::erase_one(int target) {

  if (target < size_) {
    std::size_t marker = -1;
    for (std::size_t i = 0; i < size_ && marker == -1; ++i) {
      if (data_[i] == target) {
        marker = i;
      }
    }
    if (marker == -1) {
      return false;
    }
    for (std::size_t i = marker; i < size_ - 1; ++i) {
      data_[i] = data_[i + 1];
    }
  }
  --size_;
  return true;
}

std::size_t Bag::erase(int target) {
  std::size_t count = 0;
  while (erase_one(target)) {
    ++count;
  }
  return count;
}

Bag operator + (const Bag & b1, const Bag & b2){
  Bag output;

  output +=b1;
  output +=b2;

  return output;
}

std::ostream& operator<<(std::ostream&  out, const Bag& b){
  for(std::size_t i = 0; i<b.size(); ++i){
    out<<b[i]<< " ";
    return out;
  }
}