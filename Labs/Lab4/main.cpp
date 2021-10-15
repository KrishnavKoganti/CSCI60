#include <iostream>
#include "dbiguint.h"
using namespace std;

int main(){

dbiguint h1;
dbiguint h2("101010");
dbiguint h3("342243432");

cout<<h2<<endl;
cout<<h3<<endl;
 h2+=h3;
 cout<<h2<<endl;
// h1.reserve(10);
  return 0;
}
