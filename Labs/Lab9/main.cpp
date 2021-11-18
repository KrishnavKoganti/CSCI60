#include "lbigunit.h"

int main(){

  std::string s1 = "123";
  lbiguint l1 = lbiguint(s1);

  std::cout<<l1<<std::endl;
  std::cout<<"Size of l1: "<<l1.size()<<std::endl;
  std::cout<<"2nd element of l1: "<<l1[1]<<std::endl;



  return 0;
}