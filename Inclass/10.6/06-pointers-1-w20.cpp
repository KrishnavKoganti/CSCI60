#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
/*
    int n=42;
    int* p;//this is how you declare a pointer
    //The value stored in a pointer is an address in memory

    //How do you make it so that the value stored in p is the
    //address of the variable n?
    p = &n;

    cout<<"n:"<<n<<endl;
    cout<<"p:"<<p<<endl;

    cout<<"&p:"<<&p<<endl;


    //How do you print out 42 from p?
    cout<<*p<<endl;










    n = 7;//Which of the below will be different now?
    cout<<"n:"<<n<<endl;
    cout<<"p:"<<p<<endl;
    cout<<"*p:"<<*p<<endl;







    int *p2;
    p2 = p;

    cout<<"n:"<<n<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"*p2:"<<*p2<<endl;





    *p = 2;
    cout<<"n:"<<n<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"*p2:"<<*p2<<endl;
    cout<<endl;






    int n2 = 15;
    p2 = &n2;

    cout<<"n:"<<n<<endl;
    cout<<"n2:"<<n2<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"*p2:"<<*p2<<endl;
    cout<<endl;

    n2 = 31;

    cout<<"n:"<<n<<endl;
    cout<<"n2:"<<n2<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"*p2:"<<*p2<<endl;
    cout<<endl;

    *p = n2;
    n = 17;

    cout<<"n:"<<n<<endl;
    cout<<"n2:"<<n2<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"*p2:"<<*p2<<endl;
    cout<<endl;


*/
    int n, n2, *p, *p2;
    p2 = &n2;
    n2 = 31;
    p = &n;
    n = 42;
    //First, draw the memory picture for this.
    //Which of these make sense?  For the ones that do make sense,
    //what do they do?
    *p=*p2;
    //&n=&n2;//no
    //&n=10;//no
    p=p2;

    cout<<"n:"<<n<<endl;
    cout<<"n2:"<<n<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"*p2:"<<*p2<<endl;
    cout<<endl;

}
