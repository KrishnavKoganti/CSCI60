//Lab 6
//Krishna Koganti
//Evan Yanaga


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






int main(){

  int a1[] = {6,2,3,2,6,2};
  string b1[] = {"horse", "dog", "krishna's mom", "evan's mom", "there are cockroaches in benson"};
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

  return 0;
}
