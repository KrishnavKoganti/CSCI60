//The names of everyone you served in 2019 (no duplicates).

#include <unordered_set>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/*
int meals(unordered_set<string> n){
  return n.size();
}

int people(unordered_set<string> n){
  int p = 0;
  for(unordered_set<string>::iterator it = n.begin(); it != n.end(); it++){
    if(*it != ""){
      p++;
    }
  }
  return p;
}
*/

int main(){
  unordered_set<string> names;

  ifstream inStream;
  ofstream outStream;

  inStream.open("names.txt");
  outStream.open("output1a.txt");

  string str;
  while(getline(inStream,str)){
    if(str.size()> 0){
      names.insert(str);
    }
  }
  for(unordered_set<string>::iterator it = names.begin(); it != names.end(); it++){
    outStream<<*it<<endl;
  }

  /*
  cout<< "Meals = "<<meals(names)<<endl;;
  cout<< "People  = "<<people(names)<<endl;
  cout<< "Average = "<<meals(names)/people(names)<<endl;
  */


  inStream.close();
  outStream.close();

  return 0;
}
