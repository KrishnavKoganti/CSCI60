#include "complex.h"

#include <cmath>


int Complex::magnitude(){
    int temp1 = pow(a,2);
    int temp2 = (pow(b,2));

    return sqrt(temp1+temp2);
}

Complex operator+(Complex c1 , Complex c2){
    Complex output(c1.getA()+c2.getA(),c1.getB()+c2.getB());
    return output;
}

bool operator==(Complex c1,Complex c2){
    return (c1.getA()==c2.getA() && c1.getB()==c2.getB());
    
}

std::ostream& operator <<(std::ostream &out,  Complex c){

    out<<c.getA()<<"+"<<c.getB()<<"i";

    return out;
}




