#include <iostream>

using namespace std;

class sd{

    private:

        string name;
        int capacity;
        int memory;

    public:

        sd(){
            name = " ";
            capacity = 0;
            memory = 0;
        }
        sd(string name_, int capacity_, int memory_){
            name = name_;
            capacity = capacity_;
            memory = memory_;
        }

        string getName(){
            return name;
        }

        int getCapacity(){
            return capacity;
        }

        int getMemory(){
            return memory;
        }

        // bool takePicture(){
        //     if()
        // }

        void empty(){
            
            capacity = 0;
            memory = 0;
        }

};

int main(){


    return 0;
}