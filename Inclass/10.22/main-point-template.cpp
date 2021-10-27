#include <iostream>
#include "point.h"

using namespace std;

int main(){
  Point<int> p;//We must explicitly tell C++ what T shoudl be
  Point<int>p2(5, 6);//Still need to specify type
  Point<string> p3;
  //Point isn't a class, it's instructions that C++
  //can use to generate a whole family of classes
  //(depending on what is in the <>)
  cout<<p;
  return 0;
}
