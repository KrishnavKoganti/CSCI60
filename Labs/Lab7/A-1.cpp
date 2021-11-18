//The names of everyone you served in 2019 (no duplicates).

#include <unordered_set>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  unordered_set<string> names;

  ifstream inStream;
  ofstream outStream;

  inStream.open("names.txt");
  outStream.open("output1a.txt");

  string str;
  while (getline(inStream, str))
  {
    if (str.size() > 0)
    {
      names.insert(str);
    }
  }
  for (unordered_set<string>::iterator it = names.begin(); it != names.end(); it++)
  {
    outStream << *it << endl;
  }

  inStream.close();
  outStream.close();

  return 0;
}
