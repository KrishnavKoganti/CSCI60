#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ifstream inFile;
    ofstream outFile;

    inFile.open("input.txt");
    map<int, pair<int, vector<string>>> myMap;

    string line;
    while (getline(inFile, line))
    {
        string s = line.substr(0, line.find(" "));     //gets the score
        int score = stoi(s);                           //converts the score to an int
        string name = line.substr(line.find(" ") + 1); //gets the name
        if (myMap.find(score) == myMap.end())
        {                                                  //if the score is not in the map
            myMap[score] = make_pair(1, vector<string>()); //adds the score and the name to the map
            myMap[score].second.push_back(name);           //adds the name to the vector
        }
        else
        {
            myMap[score].first++;                //adds one to the number of names with the same score
            myMap[score].second.push_back(name); //adds the name to the vector
        }

        for (int i = 0; i < prev(myMap.end())->first; i++)
        {
            if (myMap.find(i) == myMap.end())
            {
                myMap[i] = make_pair(0, vector<string>()); //adds empty map for missing numbers
            }
        }
    }

    for (map<int, pair<int, vector<string>>>::iterator it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << it->first << ":"; //prints the score

        for (int i = 0; i < it->second.first; i++)
        {
            cout << 'x'; //prints out x for the histogram
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    //prompts user to if they would like to see the names of people who got a given score
    cout << "Would you like to see the names of people who got a given score? (y/n): ";
    string answer;
    cin >> answer; //gets the answer
    if (answer == "y")
    {
        cout << "Enter the score you would like to see: ";
        int score;
        cin >> score; //gets the score
        cout << "The names of people who got " << score << " are: ";
        for (int i = 0; i < myMap[score].second.size(); i++)
        {                                           //iterates through the vector
            cout << myMap[score].second[i] << ", "; //prints out the names
        }
        cout << endl;
    }

    return 0;
}