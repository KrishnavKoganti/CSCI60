#include <iostream>

using namespace std;



double water(int n){
  if(n == 0){
    return 10;
  }else{
    return (water(n-1)/2 +1);
  }
}

int main(){

  cout<< water(5)<<endl;;

  return 0;
}
