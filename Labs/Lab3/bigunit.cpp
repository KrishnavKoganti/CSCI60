#include "BIGUINT.H"
#include <cassert>
#include "string"



biguint::biguint(){
  for (std::size_t i = 0; i < CAPACITY; i++) {
    data_[i] = 0;
  }
}

//Set all the values to 0
//For a string variable for the input
//go through the string and set each item at the first item of the array, turn that string into an int
//iterate through the array starting at 0 and setting the string equal to the array
//itterate from back to front using size-1

biguint::biguint(const std::string &s) {
  for (std::size_t i = 0; i < CAPACITY; i++) {
    data_[i] = 0;
  }
  int temp = s.size();
  std::string input = " ";
  for (std::size_t i = 0; i < s.size(); i++){

    input = s[(temp-1)];
    data_[i] = std::stoi(input,nullptr, 10);
    temp--;
  }

}

unsigned short biguint::operator [](std::size_t pos) const {
  assert(pos < CAPACITY);
  return data_[pos];

}

std::ostream& operator <<(std::ostream& out, const biguint& b){
  for(std::size_t i = 0; i < biguint:: CAPACITY; i++){
    out<< b[i]<< " ";
  }
  return out;
}



//create a variable for the leftover at the top
//use a for loop to iterate from 0 to CAPACITY
//start with the ones place( index 0) and add the ones place from both objects to the array and //store that in a variable called sum
//and then set data_[i] equal to the (sum + leftover) % 10
//set leftover equal to the sum / 10

void biguint::operator += (const biguint & b) {
 int leftover = 0;
 for (size_t i = 0; i < CAPACITY; i++) {
   int sum = b[i] + data_[i];
   data_[i] = (sum + leftover) % 10;
   leftover = sum / 10;
 }
}
