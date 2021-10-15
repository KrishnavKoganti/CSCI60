#include "dbiguint.h"
#include <cassert>
#include <string>




dbiguint::dbiguint(){
  data_ = nullptr;
  capacity_ = 0;
}

dbiguint::dbiguint(const std::string &s) {
  capacity_ = s.length();
  data_ = new unsigned short[capacity_];

  unsigned short j = 0;
      for(unsigned short i = capacity_ - 1; i > 0; i--){
        data_[j] = s[i] - '0';
        j++;
      }
      data_[capacity_ - 1] = s[0] - '0';
}

std::size_t dbiguint::size() const { return capacity_;}

unsigned short dbiguint::operator [](std::size_t pos) const {
  return data_[pos];
}

std::ostream& operator <<(std::ostream& out, const dbiguint& b){
  for(int i = b.size()-1; i >= 0; --i){
    out<< b[i]<< " ";
  }
  return out;
}

void dbiguint::reserve(std::size_t new_capacity)
{
   if (new_capacity < capacity_)
   {
       unsigned short *temp = new unsigned short[new_capacity];
       for (std::size_t i = 0; i < new_capacity; i++)
           temp[i] = data_[i];
       delete[] data_;
       data_ = temp;
       capacity_ = new_capacity;
   }
   else
   {
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


void dbiguint::operator+=(const dbiguint &b)
{
   reserve(b.size());
   for (int i = 0; i < capacity_ ; i++)
   {

       data_[i] = data_[i]+b[i];

       if (data_[i] > 9)
       {
           if (i == capacity_ - 1)
           {
             data_[i] -= 10;
             data_[i + 1]++;

           }
       }
   }
}
