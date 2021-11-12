#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  ifstream inFile;
  ofstream outFile;

  vector<string> words;
  inFile.open("input.txt");

  string str;
  while (inFile >> str)
  { //read in the file
    if (str.size() > 0)
    {
      words.push_back(str); //add the word to the vector
    }
  }
  inFile.close();

  sort(words.begin(), words.end()); //sort the vector

  int arr[words.size()];
  for (int i = 0; i < words.size(); i++)
  {
    arr[i] = count(words.begin(), words.end(), words[i]); //count the number of times the word appears
  }
  words.erase(unique(words.begin(), words.end()), words.end()); //remove duplicates

  outFile.open("output.txt");
  for (int i = 0; i < words.size(); i++)
  {
    outFile << words[i] << " : " << arr[i] << endl; //print the word and the number of times it appears
  }
  outFile.close();

  return 0;
}

