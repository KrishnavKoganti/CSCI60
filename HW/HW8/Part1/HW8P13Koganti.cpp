#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Part 1

int sequence(int n)
{
    if (n == 1 || n == 0) //base case
    {
        return 1; //returns 1 if n is 1 or 0
    }
    else
    {

        return sequence(n - 2) + n - 1; //recursive case
    }
}

//Part 3

void reverse(int a[], int first, int last) //
{
    int temp;
    if (first > last) //base case
    {
        return;
    }
    else
    {
        temp = a[first]; //swaps first and last
        a[first] = a[last];
        a[last] = temp;
        reverse(a, first + 1, last - 1); //recursive case
    }
}

int main()
{

    int a[10]; //array

    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 100; //random numbers
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " "; //prints array
    }
    cout << endl;

    reverse(a, 0, 9); //calls reverse function
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " "; //prints array
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << sequence(i) << " "; //prints sequence
    }
    cout << endl;
    return 0;
}