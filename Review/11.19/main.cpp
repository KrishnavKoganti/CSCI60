#include <iostream>

using namespace std;



//write a recursive c++ function int
//EvenSum(int n) to compute 2+4+...+2n.

int EvenSum(int n)
{
    if (n == 0)
        return 0;
    else
        return 2 + EvenSum(n - 1);
}

//write a recursive function int
//ncounter(int a[], int size, int n)) that counts the number
//of times that a value n apperas in the array.

int ncounter(int a[], int size, int n)
{
    if (size == 0)
        return 0;
    else if (a[size - 1] == n)
        return 1 + ncounter(a, size - 1, n);
    else
        return ncounter(a, size - 1, n);
}

int main(){

    for(int i = 0; i < 10; i++){
        cout << EvenSum(i) << endl;
    }

    int a[10] = {1,2,4,5,5,5,6,7,8,9};
    cout << ncounter(a, 10, 5) << endl;

    return 0;
}