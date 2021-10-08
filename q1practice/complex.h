#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <ostream>
class Complex{
    private:
        int a;
        int b;

    public:
    Complex(){
        a=0;
        b =0;

    }
    Complex(int a_, int b_){
        a = a_;
        b = b_;
    }

    int getA() {
        return a;
    }

    int getB() {
        return b;
    }
    
    int magnitude();
};

Complex operator+(  Complex c1 , Complex c2);
bool operator==( Complex c1, Complex c2);

std::ostream& operator <<(std::ostream &out,  Complex &c);
// std::ostream& operator <<(std::ostream &out, const biguint& b);

#endif