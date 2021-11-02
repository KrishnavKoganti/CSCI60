#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

// output the top 10 most commonly used words in input file

using namespace std;

int main()
{

    ifstream is("anna_karenina.txt");

    if (is.fail())
    {
        cout << "Error" << endl;
        return 1;
    }
    //How many times is each word (that's used in the file) used
    map<string, std::size_t> m;
    string temp;
    while(is>>temp){
        m[temp]++;
    }
    //Put everything in m into a container that will make it
    //easy to find out which words were used the most
    //multiset<size_t> s;
    //map<std::size_t, string>;
    multiset<pair<std::size_t, string> > ms;
    //Put everything from m into ms;
    for(auto e: m){
      pair<std::size_t, string> p;
      p.first = e.second;
      p.second = e.first;
      ms.insert(p);
    }

    //Print out the 10 most commonly used words in the file
    multiset<pair<std::size_t, string> >::reverse_iterator i;
    int count = 0;
    for(i=ms.rbegin(); i!=ms.rend()&&count<10; i++){
      cout<<(*i).first<<" "<<(*i).second<<endl;
      count++;
    }



    is.close();

    return 0;
}





















/*
 *
 * //end
 *
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

// output the top 10 most commonly used words in input.txt

using namespace std;

int main(int argc, char *argv[])
{

    ifstream is("C:\\Users\\nlinnell\\Documents\\qt\\07-MapTopTen\\anna_karenina.txt");

    if (is.fail())
    {
        cout << "Error" << endl;
        return 1;
    }

    map<string, int> m;
    string s;
    while(is>>s){
        m[s]++;
    }
    /*for (auto e:m){
        cout<<e.first<<" "<<e.second<<endl;
    }

    vector<pair<int, string>> v;
    for (auto e:m){
        v.push_back(pair<int, string>(e.second, e.first));
    }
    sort(v.rbegin(), v.rend());

    for(int i=0; i<30; i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    cout<<m.size()<<endl;
    is.close();

    return 0;
}
*/
