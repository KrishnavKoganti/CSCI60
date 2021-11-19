#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int sequence(int n){
    if (n <= 1)
        return n;
    return sequence(n-1) + sequence(n-2);
}


void reverse(int a[], int first, int last){
    int temp;
    if(first > last){
        return;
        
    }else{
        temp = a[first];
        a[first] = a[last];
        a[last] = temp;
        reverse(a, first+1, last-1);
    }
    
}



int main(){
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<sequence(10)<<endl;

    reverse(a, 0, 9);
    cout<<size<<endl;
    return 0;
}