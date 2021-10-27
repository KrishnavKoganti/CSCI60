#include <iostream>
#include "bankaccount.h"

using namespace std;
/*
int minimal(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

//function that returns the string that comes first alphabetically
string minimal(string a, string b){
    if(a<b)
        return a;
    else
        return b;
}

//Write a function that returns the BankAccount with the smaller balance
BankAccount minimal(BankAccount a, BankAccount b){
    if(a<b)
        return a;
    else
        return b;
}
*/
/*We could use the below, which would allow types that can be cast to match.
However, this is  a pretty big compromise to make to allow this, definitely a judgement call.
Much more common to use one type variable and accept the limitation that the
input types must match exactly.
//Template function
template<typename T, typename S>//This function can't be compiled to machine code
T minimal(T a, S b){//Must be compiled for each different type called with
    T x;
    if(a<b)
        x=a;
    else
        x=b;
    return x;
}
*/
//T must support <, =
template<typename T>//This function can't be compiled to machine code
T minimal(T a, T b){//Must be compiled for each different type called with
    T x;
    if(a<b)
        x=a;
    else
        x=b;
    return x;
}

//Write a template function minimal that takes in an array of any type
//and its size
//and returns its smallest element
//T must support <, be wary of shallow copy in = implementation
template <typename T>
T minimal(T a[], std::size_t size){
  T min=a[0];
  for(std::size_t i = 1; i<size; i++){
    if(a[i]<min)
      min=a[i];
  }
  return min;
}


int main()
{
  cout << minimal(5, 8)<<endl;
  string s = "hello";
  //cout<<minimal(s, "abracadabra")<<endl;//Technically, "abracadabra" is a char[] not a string
  BankAccount b1, b2;
  cout<<((minimal(b1, b2)).get_balance())<<endl;
  //cout<<minimal(5, 'a')<<endl;//input types to template function must match exactly
  int x=5;
  unsigned short y=7;


  int a[] = {4, 2, 8, 1, 9};
  cout<<minimal(a, 5)<<endl;

    return 0;
}
