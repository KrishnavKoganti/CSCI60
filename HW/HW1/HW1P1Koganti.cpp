#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//declaration
void writeletter(string names[], int nNames, char letter,ostream& out);


int main(){

    //Opening the file
    ifstream file("Names.txt");
    string line;
    string name[50];
    int temp = 0;
    //check if the file is opened
    if(file.is_open()){
        while(! file.eof()){
            getline(file,line);
            name[temp] = line;
            temp++;
            
        
        }
        file.close();
    }else{
        cout<<"error"<<endl;
    }
    //make the write file
    ofstream output("output.txt");
    //check if it was opened
    if(!output.is_open()){
        cout<<"error";
         return 0;
    }


    //method call
    writeletter(name, temp, 'B',output);
    writeletter(name, temp, 'J',output);
    writeletter(name, temp, 'T',output);
   
   

}
//pre: Must give in an array, and size for the array, a character that 
//we want the list to sorted by and an output file.
//post: it will takes the names and sort it by the given character. 
// Then it will write to file. 

void writeletter(string names[], int size, char letter,ostream& out)
{
   //for loop to go through the strings
   for(int i = 0;i < size;i++)
   {
       //check if the first letter is equal to letter and write it to the output file. 
       if(names[i].at(0) == letter)
       {
           out<<names[i]<<endl;
       }
   }
}