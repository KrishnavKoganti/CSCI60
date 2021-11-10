#include <iostream>

using namespace std;

int main()
{
    int a(5);
    const int * const pa(&a);//Neither line 13 or line 14 is allowed
    cout << a << endl;
    cout << *pa << endl;

    int b(6);
    pa=&b;//Not allowed by: int * const pa(&a);
    *pa = 7;//Not allowed by const int * pa(&a);


    cout << a << endl;
    cout << *pa << endl;

    return 0;

}
