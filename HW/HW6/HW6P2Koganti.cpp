//Lab 6


#include <cmath>
#include <iostream>

using namespace std;

//pre: T1 needs to support ==, T2 must support <
//post:returns how many of find are in the array
template <typename T1, typename T2>
int count_exact(T1 a[], T2 size, T1 find){
  int count = 0;
  for(int i=0; i<size; i++){
    if(a[i] == find){
      count++;
    }
  }
  return count;
}
 

//pre: T1 needs to support >= and <=, T2 must support <
//post: returns how many are found in a range;
template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high){
  int count = 0;
  for(int i = 0; i < size; i++){
    if(a[i]>=low && a[i]<= high){
      count++;
    }
  }
  return count;
}

template<typename T>
class dimensional{
  private:
    T val[10];
    size_t dim;
  public:
    dimensional();
    dimensional(size_t p);
    dimensional(size_t p, T s[]);
    T getItem(int index);
    size_t getSize(){return dim;}
    void operator =(dimensional a);
    void operator +=(dimensional a);
};

template<class T>
dimensional<T>::dimensional(){
  dim = 0;
}
template<class T>
dimensional<T>::dimensional(size_t p){
  dim = p;
}
template<class T>
dimensional<T>::dimensional(size_t p, T s[]){
  dim = p;
  for(size_t i=0; i<p; i++){
    val[i] = s[i];
  }
}

template<class T>
T dimensional<T>::getItem(int index){
  return val[index];
}




template <typename T>
void dimensional<T>::operator =(dimensional a){
  dim = a.getSize();
  for(short i=0; i<dim; i++){
    val[i] = a.getItem(i);
  }
}

template <typename T>
void dimensional<T>::operator +=(dimensional a){
  if(dim > a.getSize()){
    for(int i=0; i<dim; i++){
      val[i] += a.getItem(i);
    }
  }else{
    dim = a.getSize();
    for(int i=0; i<dim; i++){
      val[i] += a.getItem(i);
    }
  }
}

template <typename T>
dimensional<T>  operator +(dimensional<T> a, dimensional<T> b){
  
  T c[10];
  size_t s;
  if(a.getSize() > b.getSize()){
    s = a.getSize();
    for(int i=0; i<s; i++){
      c[i] = a.getItem(i) + b.getItem(i);
    }
  }else{
    s = b.getSize();
    for(int i=0; i<s; i++){
      c[i] = a.getItem(i) + b.getItem(i);
    }
  }
  return dimensional<T>(s, c);
}

template <typename T>
bool  operator ==(dimensional<T> a, dimensional<T> b){
  for(int i=0; i<a.getSize(); i++){
    if(a.getItem(i) != b.getItem(i)){
      return false;
    }
  }
  return true;
}
//take in two strings and return an int (the distance between the encodings of the first characters of the strings).

int operator -(string a, string b){
  return a[0] - b[0];
}
//distance between templates
template <typename T>
double distance(dimensional<T> a, dimensional<T> b){
  double dist = 0;

  for(int i=0; i<a.getSize(); i++){
    int temp = a.getItem(i) - b.getItem(i);
    dist += pow(temp, 2);
  }
  return sqrt(dist);
}







int main(){

  int a1[] = {6,2,3,2,6,2};
  int a2[] = {4,5,6,2,4,8};
  string b1[] = {"horse", "dog", "krishna's mom", "evan's mom", "there are cockroaches in benson"};
  string b2[] = {"What","is","the","meaning","of","life?"};
  string low = "horse";
  string high = "there are cockroaches in benson";

  //Problem 1
  cout<<"Problem 1:"<<endl;
  cout<<"count_exact(a1, 6, 6): "<< count_exact(a1, 6, 6)<<endl;
  string search = "dog";
  cout<<"count_exact(b1, 5, dog): "<< count_exact(b1, 5, search)<<endl;
  cout<<"\n\n";

  //Problem 2
  cout<<"Problem 2:"<<endl;
  cout<<"count_range(a1, 6, 2, 4): "<< count_range(a1, 6, 2, 4)<<endl;
  cout<<"count_range(b1, 6, 2, 4): "<< count_range(b1, 5, low, high)<<endl;
  cout<<"\n\n";

  //Problem 3
  cout<< "Problem 3:"<<endl;
  dimensional<int> c1;
  dimensional<int> c2 = dimensional<int>(6,a1);
  dimensional<string> c3 = dimensional<string>(5, b1);
  dimensional<int> c4 = dimensional<int>(9);
  cout<<"c2.size(): "<<c2.getSize()<<endl;
  cout<<"c3.getItem(3): "<<c3.getItem(3)<<endl;
  cout<<"\n\n";

  //Problem 4
  cout<< "Problem 4:"<<endl;
  c1 = c2;
  cout<<"c2.getSize(): "<<c2.getSize()<<endl;
  cout<<"c2.getItem(4): "<<c2.getItem(4)<<endl;

  //Problem 5
  dimensional<string> d1 = dimensional<string>(5, b1);
  dimensional<string> d2 = dimensional<string>(6, b2);

  cout<< "Problem 5:"<<endl;
  d1 += d2;
  for(int i=0; i<d1.getSize(); i++){
    cout<<d1.getItem(i)<<endl;
  }

  //Problem 6
  dimensional<string> e1 = dimensional<string>(5, b1);
  dimensional<string> e2 = dimensional<string>(6, b2);
  cout<< "Problem 6:"<<endl;
  dimensional<string> e3 =e1 + e2;
  for(int i=0; i<e3.getSize(); i++){
    cout<<e3.getItem(i)<<endl;
  }

  //Problem 7
  dimensional<int> f1 = dimensional<int>(6, a1);
  dimensional<int> f2 = dimensional<int>(6, a2);
  cout<< "Problem 6:"<<endl;
  cout<< " == "<<(f1 == f2)<<endl;
  dimensional<int> f3 =f1 + f2;
  for(int i=0; i<f3.getSize(); i++){
    cout<<f3.getItem(i)<<endl;
  }
 
  //Problem 8
  dimensional<int> h1 = dimensional<int>(6, a1);
  dimensional<int> h2 = dimensional<int>(6, a2);
  cout<< "Problem 8:"<<endl;
 
  double h3 = distance(h1, h2);
  cout<< " distance "<<h3<<endl;

  dimensional<string> i1 = dimensional<string>(5, b1);
  dimensional<string> i2 = dimensional<string>(6, b2);
  cout<< "Problem 8:"<<endl;
  
   double i4 = distance(i1, i2);
   cout<< " distance "<<i4<<endl;
  


  return 0;
}
