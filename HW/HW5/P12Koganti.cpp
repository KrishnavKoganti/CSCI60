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


//test dUSet contructor 
DynamicBag t;

t.insert(5);
t.insert(5);
t.insert(6);
t.insert(7);
cout<<t<<endl;
dUSet h(t);
cout<<"h:"<<h<<endl;

//test dSet insert and contructor
DynamicBag l;
l.insert(5);
l.insert(6);
l.insert(5);
l.insert(7);
l.insert(10);
l.insert(7);
dSet p(l);

cout<<"p:"<<p<<endl;

//test dUSet insert
dUSet k;
k.insert(5);
k.insert(5);
k.insert(6);
k.insert(7);
cout<<"k:"<<k<<endl;

//test dSet insert
dUSet g;
g.insert(5);
g.insert(6);
g.insert(5);
g.insert(7);
g.insert(10);
g.insert(7);
cout<<"g:"<<g<<endl;





return 0;
}
