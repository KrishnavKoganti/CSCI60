#include <iostream>
#include "BIGUINT.H"

using namespace std;

int main() {

  biguint biguint1;
  biguint biguint2 = biguint("32454");
  biguint biguint3 = biguint("34342443");

  cout << biguint2 << endl;

  biguint2 += biguint3;

  cout<< biguint2 << endl;

  return 0;
}
