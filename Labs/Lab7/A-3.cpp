//A running list of everyone you served in 2019, in the order they were served (with duplicates).

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int meals(vector<string> n){
  return n.size();
}

int main(){
  vector<string> names;

  ifstream inStream;
  ofstream outStream;

  inStream.open("names.txt");
  outStream.open("output1c.txt");

  string str;
  while(getline(inStream,str)){
    if(str.size()> 0){
      names.push_back(str);
    }
  }
  for(int i = 0; i<names.size(); i++){
    outStream<<names[i]<<endl;
  }
  // for(vector<string>::iterator it = names.begin(); it != names.end(); it++){
  //   outStream<<*it<<endl;
  // }




  inStream.close();
  outStream.close();

  return 0;
}
