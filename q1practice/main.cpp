#include "complex.h"
#include <iostream>
#include <cmath>



using namespace std;

int main() 
{
    Complex m(1, 2), n(3, 6), p;
    cout<<p<<endl;
    cout<<(m+n)<<endl;
    cout<<(m==n)<<endl;
    cout<<(m==m)<<endl;
    cout<<m.magnitude()<<endl;
    cout<<m.getA()<<endl;


    return 0;
}
