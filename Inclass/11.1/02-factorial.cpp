#include <iostream>

using namespace std;

int factorial(int n);
int main()
{
    cout << factorial(5) << endl;
    return 0;
}


int factorial(int n){
  if(n==1){//Base Case
    return 1;
  }
  else{//Recursive Case
    return n*factorial(n-1);
  }
}




















/*
int factorial(int n){
if(n==0||n==1){
    return 1;
}
else{
    return n*factorial(n-1);
}
}
*/
