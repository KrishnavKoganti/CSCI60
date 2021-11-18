//The names of everyone you served in 2019 (no duplicates).

#include <map>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

double meals(map<string, int> n)
{
  double meal = 0;
  for (map<string, int>::iterator it = n.begin(); it != n.end(); it++)
  {
    meal += it->second;
  }
  return meal;
}

double people(map<string, int> n)
{
  double p = 0;
  for (map<string, int>::iterator it = n.begin(); it != n.end(); it++)
  {
    p++;
  }
  return p;
}

int main()
{
  map<string, int> names;

  ifstream inStream;
  ofstream outStream;

  inStream.open("names.txt");
  outStream.open("output1b.txt");

  string str;
  while (getline(inStream, str))
  {
    if (str.size() > 0)
    {
      if (names.find(str) != names.end())
      {
        names[str] += 1;
      }
      else
      {
        names[str] = 1;
      }
    }
  }

  for (map<string, int>::iterator it = names.begin(); it != names.end(); it++)
  {
    outStream << it->first << " : " << it->second << endl;
  }

  inStream.close();
  outStream.close();

  cout << "Meals = " << meals(names) << endl;
  cout << "People  = " << people(names) << endl;
  cout << "Average = " << meals(names) / people(names) << endl;

  return 0;
}
