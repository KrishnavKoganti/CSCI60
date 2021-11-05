#include <iostream>

using namespace std;

//Part 1
//type variables: >

template <class T>
T abs(T a, T b){
    if(a > b)
        return a;
    else
        return b;
}

//Part 3
// type variables: >, = , == 
template <class T1>
T1 frequent(T1 a[], std::size_t size){
    T1 max = a[0];
    T1 max_count = 0;
    for(int i = 0; i < size; i++){
        int count = 0;
        for(int j = 0; j < size; j++){
            if(a[i] == a[j])
                count++;
        }
        if(count > max_count){
            max_count = count;
            max = a[i];
        }
    }
    return max;
}






int main(){
    int a = 5;
    int  b = 10;
    int temp = abs(a,b);
    cout << temp << endl;  

    int c[6] = {3,2,7,3,2,2};
    size_t size = 6;
    int temp2 = frequent(c, size);
    cout << temp2 << endl;

    return 0;
}