#include "BIGUINT.H"
#include <iostream>

using namespace std;

int main() {

  biguint biguint1;
  biguint biguint2 = biguint("32454");
  biguint biguint3 = biguint("34342443");

  cout << biguint2 << endl;

  biguint2 += biguint3;
  biguint biguint7 = biguint1 + biguint2;
  cout << biguint2 << endl;
  cout << biguint7 << endl;

  biguint biguint4 = biguint("3434324");
  biguint biguint5 = biguint("2432");
  biguint biguint6 = biguint4 - biguint5;
  biguint4 -= biguint5;

  cout << biguint4 << endl;
  cout << biguint6 << endl;
  bool o1 = biguint1 < biguint2;
  cout << o1 << endl;
  bool o2 = biguint1 > biguint2;
  cout << o2 << endl;
  bool o3 = biguint1 <= biguint2;
  cout << o3 << endl;
  bool o4 = biguint1 >= biguint2;
  cout << o4 << endl;
  bool o5 = biguint1 == biguint2;
  cout << o5 << endl;
  bool o6 = biguint1 != biguint2;
  cout << o6 << endl;

  cout << biguint2.toString() << endl;

  return 0;
}
