#include <iostream>

using namespace std;

/*
Part A:
If a[i] < a[i+1] then the array is sorted

Part B:
We can do a[n-2] < a[n-1]
*/

bool isSorted2(int a[], int n){
  //cout<<n<<endl;
  if(n==0){
    return true;
  }else{
    if(a[n-1] >= a[n-2]){
      return isSorted2(a, n-1);
    }else{
      return false;
    }
  }
}

int main(){

    int a[] = {1,2,3,4,5};
    int a2[] = {4,3,5,3,2};
    int a3[] = {1,2,3,4,2};
    int a4[] = {5,2,4,5,6};

    cout<<isSorted2(a,5)<<endl;
    cout<<endl;
    cout<<isSorted2(a2,5)<<endl;
    cout<<endl;
    cout<<isSorted2(a3,5)<<endl;
    cout<<endl;
    cout<<isSorted2(a4,5)<<endl;
  return 0;
}
