#include "dbiguint.h"
#include <cassert>
#include <cstddef>
#include <string>
#include <cmath>
dbiguint::dbiguint() {
  data_ = nullptr;
  capacity_ = 0;
}

dbiguint::dbiguint(const std::string &s) {
  capacity_ = s.length();
  data_ = new unsigned short[capacity_];

  unsigned short j = 0;
  for (unsigned short i = capacity_ - 1; i > 0; i--) {
    data_[j] = s[i] - '0';
    j++;
  }
  data_[capacity_ - 1] = s[0] - '0';
}

dbiguint::~dbiguint() {
  delete[] data_;
  data_ = nullptr;
  capacity_ = 0;
}

void dbiguint::operator=(const dbiguint &b) {
  delete [] data_;
  capacity_ = b.capacity_;
  data_ = new unsigned short[capacity_];
  for(std::size_t i = 0; i < capacity_; i++){
    data_[i]=b.data_[i];
  }
}

std::size_t dbiguint::size() const { return capacity_; }

unsigned short dbiguint::operator[](std::size_t pos) const {
  return data_[pos];
}

int dbiguint::compare(const dbiguint &b) const {
  int temp;
  if (b.capacity_ < capacity_) {
    for (std::size_t i = 0; i < b.capacity_; i++) {
      if (data_[i] > b[i]) {
        temp = 1;
      } else if (data_[i] == b[i]) {
        temp = 0;
      } else if (data_[i] < b[i]) {
        temp = -1;
      }
    }
  } else {
    for (std::size_t i = 0; i < b.capacity_; i++) {
      if (data_[i] > b[i]) {
        temp = 1;
      } else if (data_[i] == b[i]) {
        temp = 0;
      } else if (data_[i] < b[i]) {
        temp = -1;
      }
    }
  }
  return temp;
}

std::ostream &operator<<(std::ostream &out, const dbiguint &b) {
  for (int i = b.size() - 1; i >= 0; --i) {
    out << b[i] << " ";
  }
  return out;
}
// std::istream & operator >> (std::istream & out, dbiguint & b){
//   out<< b.data_ <<b.capacity_;
//   return out;
// }

void dbiguint::reserve(std::size_t new_capacity) {
  if (new_capacity < capacity_) {
    unsigned short *temp = new unsigned short[new_capacity];
    for (std::size_t i = 0; i < new_capacity; i++)
      temp[i] = data_[i];
    delete[] data_;
    data_ = temp;
    capacity_ = new_capacity;
  } else {
    unsigned short *temp = new unsigned short[new_capacity];
    for (std::size_t i = 0; i < capacity_; i++)
      temp[i] = data_[i];
    for (std::size_t i = capacity_; i < new_capacity; i++)
      temp[i] = 0;

    delete[] data_;
    data_ = temp;
    capacity_ = new_capacity;
  }
}

void dbiguint::operator+=(const dbiguint &b) {
  reserve(b.size());
  for (int i = 0; i < capacity_; i++) {

    data_[i] = data_[i] + b[i];

    if (data_[i] > 9) {
      if (i == capacity_ - 1) {
        data_[i] -= 10;
        data_[i + 1]++;
      }
    }
  }
}

void dbiguint::operator-=(const dbiguint &b) {

  // if (capacity_ < b.capacity_) { //checks the size
    this->reserve(b.size());// reserves space

    for (size_t i = 0; i < capacity_; i++) {
      if (data_[i] - b[i] < 0) {// checks if difference is >0
        data_[i + 1] -= 1;// subtracts 1 from the spot above
        data_[i] = (10 + data_[i]) - b[i];// added 10 
      } else {
        data_[i] -= b[i];// subtracts
      }
    }
 // }

  //getting rid of the leading 0's
  std::size_t counter = 0; //counter
  std::size_t new_capacity; // size of new array

  for(int i = 0 ; i < capacity_-counter-1 ; i++){//finds the amount of leading 0's
    if(data_[i] == 0){
      counter++;
      
    }
  }
  if(capacity_ - counter < capacity_){// checks if the new capacity needs to be smaller
    new_capacity = capacity_ - counter-1;// sets new capacity
    this -> reserve(new_capacity);//reserves new capacity
  }
}

void dbiguint::operator *=(const dbiguint & b){
  std::size_t product = 0;
  for(std::size_t i = 0; i < capacity_; i++){//go through the first number
    for(std::size_t k = 0; k < b.capacity_; k++){//go through the second number
      product = (data_[i] * (int)pow(10,i)*(b[k]* (int)pow(10,i)));
      std::cout<<product<<"\n";
    }
  }
  std::string temp = std::to_string(product);
  dbiguint output(temp);//make product into a string and make a new dbiguint
  // delete [] data_;
  int size = temp.length()+1;
  data_ = new unsigned short[capacity_];
  // std::cout<<output.size()<<"\n";

  for(std::size_t i = capacity_+b.size(); i >0; i--){
    std::cout<<output.data_[i]<<"o\n";
    data_[i]+= output.data_[i];
    std::cout<<data_[i]<<"d\n";
  }
}

dbiguint operator+(const dbiguint &lhs, const dbiguint &rhs) {
  dbiguint temp;
  temp += lhs;
  temp += rhs;
  return temp;
}

dbiguint operator-(const dbiguint &lhs, const dbiguint &rhs) {
  dbiguint temp;
  temp += lhs;
  temp -= rhs;
  return temp;
}

bool operator<(const dbiguint &lhs, const dbiguint &rhs) {
  bool temp;
  int comp = lhs.compare(rhs);
  if (comp == -1) {
    temp = true;
  } else {
    temp = false;
  }
  return temp;
}
bool operator<=(const dbiguint &lhs, const dbiguint &rhs) {
  bool temp;
  int comp = lhs.compare(rhs);
  if (comp <= 0) {
    temp = true;
  } else {
    temp = false;
  }
  return temp;
}
bool operator!=(const dbiguint &lhs, const dbiguint &rhs) {
  bool temp;
  int comp = lhs.compare(rhs);
  if (comp != 0) {
    temp = true;
  } else {
    temp = false;
  }
  return temp;
}
bool operator==(const dbiguint &lhs, const dbiguint &rhs) {
  bool temp;
  int comp = lhs.compare(rhs);
  if (comp == 0) {
    temp = true;
  } else {
    temp = false;
  }
  return temp;
}
bool operator>=(const dbiguint &lhs, const dbiguint &rhs) {
  bool temp;
  int comp = lhs.compare(rhs);
  if (comp >= 0) {
    temp = true;
  } else {
    temp = false;
  }
  return temp;
}
bool operator>(const dbiguint &lhs, const dbiguint &rhs) {
  bool temp;
  int comp = lhs.compare(rhs);
  if (comp == 1) {
    temp = true;
  } else {
    temp = false;
  }
  return temp;
}
