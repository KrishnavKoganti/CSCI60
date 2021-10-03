#include <iostream>

using namespace std;

struct Time{//military time, no am/pm
  int hour;
  int minute;
};

struct Carpool{
  string members[5];
  int num;
  Time arrival;
};

Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

/*
1. create a new car
2. create if else statements to check if there are more than 5 people per Carpool
3. if there are less than 5 we use a for loop to add them to the new car
4. if the car has more than 5 we will set the members to 0
5. Use the the earlier function to figure out who came first and set it to the new arrival time
*/

Carpool combineCarpool(Carpool car1, Carpool car2){
  Carpool car;
    if (car1.num + car2.num <= 5){
      car.num = 0;
      for(int i = 0; i<car1.num; i++){
        car.members[car.num++] = car1.members[i];
      }
      for(int i = 0; i<car2.num; i++){
        car.members[car.num++] = car2.members[i];
      }
      car.arrival = earlier(car1.arrival, car2.arrival);
    }else{
      car.num = 0;
    }
    return car;
}


int main(){
  Carpool car1 = {{"Bob","Mary","George"},3,{10,20}};
  Carpool car2 = {{"Tom","Jerry"},2,{4,19}};
  Carpool car = combineCarpool(car1, car2);
  cout << car.num <<endl;
  cout << car.arrival.hour <<endl;
  cout << car.arrival.minute <<endl;
  for(int i = 0; i<car.num; i++){
    cout<<car.members[i]<<endl;
  }
  return 0;

}
