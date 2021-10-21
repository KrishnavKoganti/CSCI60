
#include "dbiguint.h"
#include <iostream>
using namespace std;

int main(){

dbiguint h1;
dbiguint h2("111111");
dbiguint h3("22222222");

cout<<"h2: "<<h2<<endl;
cout<<"h3: "<<h3<<endl;
 h2+=h3;
 cout<<"+=: "<<h2<<endl;
 h2-=h3;
cout<<"-=: "<<h2<<endl;

dbiguint h4("100");
dbiguint h5("20");
h4*=h5;
cout<<"*=: "<<h4<<endl;


// h1.reserve(10);
  

  bool o1 = h2 < h3;
  cout << o1 << endl;
  bool o2 = h2 > h3;
  cout << o2 << endl;
  bool o3 = h2 <= h3;
  cout << o3 << endl;
  bool o4 = h2 >= h3;
  cout << o4 << endl;
  bool o5 = h2 == h3;
  cout << o5 << endl;
  bool o6 = h2 != h3;
  cout << o6 << endl;

  return 0;
}


