#include "Rational.h"

Rational::Rational(int n, int d){
  numer_ = n;
  denom_ = d;
}
Rational::Rational(){
  numer_ = 0;
  denom_ = 1;
}

void Rational::set_denom(int d){
  assert(d!=0);
  denom_ = d;
}


void Rational::operator *=(Rational b){
  numer_ = (numer_*b.numer_);
  denom_ = (denom_*b.denom_);
  reduce();
}


void Rational::operator +=(Rational b){
  numer_ = (numer_*b.denom_)+(b.numer_*denom_);
  denom_ = (denom_*b.denom_);
  reduce();
}


void Rational::reduce(){
  int numer = numer_;
  int denom = denom_;

  while (numer != denom){
    if(numer > denom){
      (numer -=denom);
    }else{
      (denom -= numer);
    }
  }
  numer_ /= numer;
  denom_ /= numer;
  
}

std::ostream& operator <<(std::ostream& out, Rational r){
  out<<r.numer()<<"/"<<r.denom();
  return out;
}

Rational operator +(Rational a, Rational b){
  Rational ans = Rational(0,1);
  ans+=a;
  ans+=b;
  ans.reduce();
  return ans;
  
}

Rational operator *(Rational a, Rational b){

    Rational ans = Rational(1, 1);
    ans*=a;
    ans*=b;
    ans.reduce();
    return ans;


}
bool operator ==(Rational lhs, Rational rhs){
  lhs.reduce();
  rhs.reduce();
  return (lhs.numer() == rhs.numer() && lhs.denom() == rhs.denom());
}




