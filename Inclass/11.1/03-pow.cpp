

#include <iostream>

using namespace std;
int pow(int a, int n);
int main()
{
    cout << pow(5, 3) << endl;
    return 0;
}

int pow(int a, int n){
  if(n==0){//Base Case
    return 1;
  }
  else{//Recursive Case
    return a*pow(a, n-1);
  }
}


















/*
int pow(int a, int n)
{
    if(n<0){//error handling - it's nice but not necessary unless specifically asked for.
        return -1;
    }
    else if (n==0){
        return 1;
    }
    else{
       return a*pow(a, n-1);
    }
}



int pow(int a, int n)
{
    int result = 1;
    for(int i = n; i>0; i--)
    {
        result *= a;//result = result*a;
    }
    return result;
}
*/
