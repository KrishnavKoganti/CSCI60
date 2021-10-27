#include "dUSet.h"
#include "dSet.h"
#include <cstddef>

dSet::dSet():dUSet(){};

dSet::dSet(DynamicBag &b):dUSet(){

    for(std::size_t i = 0; i < b.size()-1; i++){
    
            if((*this)[i]>(*this)[i+1]){
                int temp = (*this)[i];
                this->insertAt((*this)[i],i+1);
                this->insertAt((*this)[i+1],temp);
                std::cout<<"swap\n";
            }
            
        
    }

}