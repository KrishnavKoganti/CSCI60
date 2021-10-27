#include "dynamicbag.h"
#include <iostream>
#include <cstdlib>
#include "dUSet.h"
#include "dSet.h"
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
DynamicBag t;

t.insert(5);
t.insert(5);
t.insert(6);
t.insert(7);
cout<<t<<endl;
dUSet h(t);
cout<<"h:"<<h<<endl;
dSet p(t);
cout<<"p:"<<p<<endl;


dUSet k;
k.insert(5);
k.insert(5);
k.insert(6);
k.insert(7);
cout<<"k:"<<k<<endl;





return 0;
}
