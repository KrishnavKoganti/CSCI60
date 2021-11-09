#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{

    ifstream inFile;
    ofstream outFile;

    set<string> words; //set of words
    inFile.open("input.txt");
    string str;
    while (inFile >> str)
    { //read in file
        if (str.size() > 0)
        {
            words.insert(str); //inserts the word into the set
        }
    }
    inFile.close();

    outFile.open("output.txt");
    for (set<string>::iterator it = words.begin(); it != words.end(); it++)
    {                           //iterates through the set
        outFile << *it << endl; //prints the words to the output file
    }
    outFile.close();

    return 0;
}