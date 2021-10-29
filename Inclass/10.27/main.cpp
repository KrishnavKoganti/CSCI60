#include "dynamicbag.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
DynamicBag b;//capacity_ = 0
b.insert(5);//capacity_ = 1
b.insert(70);//capacity_ = 2
for(int i=0; i<5; i++)//i==0, capacity_ = 4;
    b.insert(i+1);//i==2, capacity_ = 8
cout<<b<<endl;
b.erase(5);
cout<<b<<endl;
}
