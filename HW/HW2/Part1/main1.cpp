#include "Rational.h"
#include <iostream>
using namespace std;

int main(){
  Rational r1 = Rational(25, 100), r2(4, 16);
  Rational r;
  //Rational r3 = r1.mult(r2);
  Rational r3 = r1*r2;//Think of as r1.*(r2)
  r2*=r1;//r2.*=(r1)
  (cout<<r3.numer())<<"/"<<r3.denom()<<endl;
  //what does the code in () return?  It better be cout!  because after the return we want the next line to happen
  cout<<"/"<<r3.denom()<<endl;
  cout<<r3<<endl;//Must be overloaded as non member,
  //because first parameter is cout, NOT the Rational

}
