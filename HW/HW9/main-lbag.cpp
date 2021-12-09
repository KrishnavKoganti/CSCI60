#include <iostream>
#include <cmath>
#include "lbag.h"

using namespace std;

int main(int argc, char *argv[])
{
  LBag<int> b, d;
  b.insert(5);
  b.insert(2);
  b.insert(7);
  b.insert(1);
  cout<<b<<endl;
  d = b;
  cout<<b<<endl;
  cout<<d<<endl;
  d.insert(5);
  LBag<int> a(d);
  cout<<b<<endl;
  cout<<d<<endl;
  cout<<a<<endl;
  cout<<a.count(5)<<endl;
  cout<<a.size()<<endl;
  cout<<"HW9: Part 1"<<endl;
  LBag<int> x, y;
  for(int i = 0; i < 5; i++){
    x.insert(rand()%100+1);
  }
  for(int i = 0; i < 5; i++){
    y.insert(rand()%100+1);
  }
  cout<<"x: "<<x<<endl;
  cout<<"y: "<<y<<endl;
  LBag<int> z = x + y;
  cout<<"x + y: "<<z<<endl;
  x+=y;
  cout<<"+=: "<<x<<endl;
  cout<<"HW9: Part 2"<<endl;

  LBag<int> k, r;
  for(int i = 0; i < 5; i++){
    k.insert(rand()%5+1);
    r.insert(rand()%5+1);
  }
  cout<<"k: "<<k<<endl;
  cout<<"r: "<<r<<endl;
  int value = 3;
  cout<<"value: "<<value<<endl;
  k.erase_one(value);
  r.erase(value);
  cout<<"k: "<<k<<endl;
  cout<<"r: "<<r<<endl;






  



    return 0;
}
