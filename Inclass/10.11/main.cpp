#include "dynamicbag.h"
#include "dynamicbag.cpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    DynamicBag b;
    b.insert(5);
    b.insert(70);
    for(int i = 0; i<5; i++){
        b.insert(i+1);
    }
    cout<<b<<endl;
    b.erase(5);
    cout<<b<<endl;

    return 0;
}