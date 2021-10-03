#include <iostream>
#include <iomanip>
#include<cstring>
#include <cstdlib>
#include <string>
#include <array>

using namespace std;

struct Animal{
    string name;
    char gender;
    int age;
    int price;
    string type;

};
Animal cheapest(string type, Animal a[], int size);
bool livetogether(Animal a, Animal b);

int main(){
    Animal a1;
    a1.name="Rob";
    a1.gender='M';
    a1.age=2;
    a1.price=6454;
    a1.type="Dog";

    Animal a2;
    a2.name="Karen";
    a2.gender='F';
    a2.age=9;
    a2.price=2334;
    a2.type="Dog";

    Animal a3;
    a3.name="Tim";
    a3.gender='M';
    a3.age=4;
    a3.price=5643;
    a3.type="Dog";

    Animal a4;
    a4.name="ButterBall";
    a4.gender='F';
    a4.age=1;
    a4.price=9898;
    a4.type="Cat";

    Animal a5;
    a5.name="Ghost";
    a5.gender='M';
    a5.age=13;
    a5.price=1341;
    a5.type="Cat";
    
    Animal s[5]={a1,a2,a3,a4,a5};

    Animal inexpensive = cheapest("Da3g", s, 5);
    
    cout<<inexpensive.name<< endl;
    cout<<inexpensive.gender<< endl;
    cout<<inexpensive.age<< endl;
    cout<<inexpensive.price<< endl;
    cout<<inexpensive.type<< endl;

    return 0;
}
//pre: Takes in the type of animial{Cat and Dog}, 
//the array of struct animals and the size of the array
//post: first it compares the the animal type to the given type
// if that is true then it gets the prices and comapres it to the lowest
// if it is lower it is set to the lowest and in the end the lowest is returned
Animal cheapest(string type, Animal a[], int size){
    int temp = 0;
    // for loop to go through the Animal array
    for(int i = 0; i< size; i++){
        //check if the given type is the same as animal type
        if(a[i].type.compare(type) == 0){
            //check the price of the anmial versus the previous lowest price
            if(a[temp].price > a[i].price){
                //if it is the lower, it is set as the lowest
                temp = i;
                cout<<"test"<<endl;
            }
        }
    }
    return a[temp];

} 
//pre: Takes in two differnt animals
//post: check if the two animals types are the same
// if they are it return true if not it returns false
bool livetogether(Animal a, Animal b){
    if(a.type.compare(b.type) == 0){
        return true;
    }
    return false;
}