//Make the file #include-able
#ifndef RATIONAL_H  //if not defined, matching endif at the end
#define RATIONAL_H  //then define
#include <iostream>
#include <cassert>
//ADT Style:  no using namespace std
class Rational{
public:
    Rational(int n, int d);
    Rational();

    int numer(){  return numer_; }//ADT Style:give the getter the variable name minus the _
    int denom(){  return denom_; }

    //pre:  d cannot be 0
    //post:  denom_ is updated to the value passed in.
    void set_denom(int d);

    //pre: none
    //post: modifies the numer_ and denom_ to reflect the result
    //of multiplying this Rational and the Rational passed in.
    //The result is not reduced; the denominator will be the product
    //of the denominators of the operands.
    void operator *=(Rational b);

    //pre: none
    //post: modifies the numer_ and denom_ to reflect the result
    //of multiplying this Rational and the Rational passed in.
    //The result is not reduced; the denominator will be the product
    //of the denominators of the operands.
    void operator +=(Rational b);

    //pre: none
    //post: converts Rational to its most reduced form. 
    void reduce();


  private:
      int numer_;//ADT Style: trailing _ means this is a private variable
      int denom_;
};
std::ostream& operator <<(std::ostream& out, Rational r);//Need the std:: because we aren't using the standard namespace
//pre: none
//post: returns a Rational that is the result of adding the
//two Rational parameters
//The result is not reduced; the denominator will be the product
//of the denominators of the operands.
Rational operator +(Rational a, Rational b);

//pre: none
//post: returns a Rational that is the result of multiplying the
//two Rational parameters
//The result is not reduced; the denominator will be the product
//of the denominators of the operands.
Rational operator *(Rational a, Rational b);

//pre:nine
//post: returns a bool that is the result of comparing the 
//two Rational parameters
// if they are a equal it will return true if not it will return 
//false
bool operator ==(Rational lhs, Rational rhs);

#endif
