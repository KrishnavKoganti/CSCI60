#include <iostream>

using namespace std;




double salary(int t){
  //base Case
  if(t == 0){
    return 50000;
  }
 

  return ((1.1*salary(t-1))+(5000));
}

int main(){
  for(int i=0; i<5; i++){
    cout<<salary(i)<<endl;
  }

  return 0;
}
