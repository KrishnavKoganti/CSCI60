#ifndef DSET_H
#define DSET_H
#include "dUSet.h"
#include "dynamicbag.h"


class dSet:public dUSet{
    public:
    //default constructor that takes in no arguments 
        dSet();
        //takes in a dynamicbag and sorts it and get rid of duplicates
        dSet(DynamicBag &b);
        //inserts target in the correct order and get rid of duplicates
        void insert(int target);

    private:
    //sorts the dynamicbag for the constructor 
    DynamicBag sort(DynamicBag &b);




};

#endif