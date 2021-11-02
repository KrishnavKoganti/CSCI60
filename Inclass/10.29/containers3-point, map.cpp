#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
  pair<string, int> p;
  p.first = "hello";
  p.second = 5;

  map<string, int> m;
  m["Mon"] = 1;
  m["Tues"] = 0;
  m["Wed"]  = 12;
  m["Thurs"] = 7;
  m["Fri"] = 7;

  cout<<m["Mon"]<<endl;//Prints 1
  cout<<m["Sat"]<<endl;//

  for(auto e: m){

    cout<<e.first<<" "<<e.second<<endl;
  }


}
