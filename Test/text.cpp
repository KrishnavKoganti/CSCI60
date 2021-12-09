// get rid of all comments
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

    ifstream inStream;
    ofstream outStream;

    inStream.open("input.txt");
    outStream.open("output1a.txt");

    string str;
    string score[100];
    string first[100];
    string last[100];
    int i = 1;
    while (getline(inStream, str))
    {
        //acount for the hwite space
        if (str.length() > 0)
        {
            score[i] = str.substr(0, str.find(" "));
            last[i] = str.substr(str.find(" ") + 1,(str.find(" ") + 2));
            first[i] = str.substr(str.find(" ") + 3, str.length());

            cout<<score[i]<<" "<<first[i]<<last[i]<<endl;
            i++;
        }


      
        
    }
    int temp = i-1;
    for (int j = 0; j < temp; j++)
    {
        cout<<score[j-1]<<" "<<first[j+1]<<last[j+1]<<endl;
        // outStream << name[j+1] << " " << score[temp - j]<<endl;
    }

    inStream.close();
    outStream.close();

    return 0;
}
