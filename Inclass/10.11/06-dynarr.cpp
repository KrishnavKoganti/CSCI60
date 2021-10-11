#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{


  int a[5];
  int size(5);
  cout<<a<<endl;



  for(int i=0; i<size; ++i){
    a[i] = 10;
    cout<<a[i]<<" ";
  }
cout<<endl;

for(int* i=a; i<(a+size); ++i){
  *i = 10;
  cout<<*i<<" ";
}
cout<<endl;

for(int i=0; i<size; ++i){
  *(a+i) = 10;
  cout<<*(a+i)<<" ";
}
cout<<endl;



int size2;
cout<<"What should size be?"<<endl;
cin>>size2;

int*p;
p=new int[size2];

for(int* i=p; i<(p+size); ++i){
  *i = 10;
  cout<<*i<<" ";
}
cout<<endl;

for(int i=0; i<size; ++i){
  p[i] =i;
  cout<<p[i]<<" ";
}
cout<<endl;



int* p2 = new int[size2+4];

for(int i = 0; i<size2; ++i){
  p2[i]=p[i];
}

delete [] p;
p=p2;

int value;
cout<<"What should I put in the last four spots?"
cin>>value;

for(i=size2; i<size2+4; ++i){
  p[i] = value;
}

size2+=4;



return 0;
}
