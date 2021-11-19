#include <iostream> 
#include <string>
#include <vector>

using namespace std;



int sequence(int n){
    if(n == 1 || n == 0){
        return 1;
    
   }else {
       
        return sequence(n-2) + n-1;
        
       
   }
 
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
    //array of generated random numbers
    int a[10];
    //generate random numbers
    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
    }
    for(int i = 0; i < 10; i++){
        cout<<a[i]<<" ";
       
    }
    cout<<endl;

    reverse(a, 0, 9);
    for(int i = 0; i < 10; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < 8; i++){
        cout<<sequence(i)<<" ";
    }
    cout<<endl;
    return 0;
}