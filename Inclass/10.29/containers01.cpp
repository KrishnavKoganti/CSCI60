#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  //vector stores items in the order they're inserted

    set<double> s;
    //No duplicates, items are stored in sorted order
    s.insert(2.3);
    s.insert(5);
    s.insert(2.3);
    s.insert(44);
    s.insert(9.6);
    s.insert(2.3);
    s.insert(1.2);
    /*
    for(int i = 0; i<s.size(); ++i){
      cout<<s[i]<<endl;
    }
    */
    for(auto i:s){
      cout<<i<<endl;
    }








    cout<<endl<<endl;
    multiset<double> m;
    //Stored in sorted order, duplicates ARE allowed
    m.insert(5);
    m.insert(1.2);
    m.insert(2.3);
    m.insert(2.4);
    m.insert(2.3);
    m.insert(5);
    m.insert(2.3);

    for(auto e:m){
      cout<<e<<endl;
    }
    cout<<endl<<endl;






    unordered_set<double> u;
    //no duplicates, stored in no particular order (and order can change!)
    u.insert(53);
    u.insert(5.3);
    u.insert(53);
    u.insert(5.3);
    u.insert(530);
    for(auto e:u){
      cout<<e<<endl;
    }





    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(9);

    for(auto e:v){
      cout<<e<<endl;
    }




//Each container type/class has certain things
//1: iterator type; like a pointer that at any time
//is pointing at one item in the container; allows programmer
//to traverse the container
//2: begin() function that returns an iterator
//that points at the first item in the container
//3: end() function that returns an iterator that
//tells us when we've seen everything
//points "one past" the last element NOT at the last element
//4.  The iterator type supports ++ (go to the next item), ==
// (point at the same spot?), and * (the dereference operator) which
//means give me the actual value I'm currently pointing at
for(auto e:v){
  cout<<e<<endl;
}
vector<int>::iterator i;
for(i=v.begin(); i!=v.end(); ++i){
  cout<<(*i)<<endl;
}
vector<int>::reverse_iterator j;
for(j=v.rbegin(); j!=v.rend(); ++j){
  cout<<(*j)<<endl;
}
unordered_set<string> u2;
for(auto e:u2){
  cout<<e<<endl;
}
unordered_set<string>::iterator i2;
for(i2=u2.begin(); i2!=u2.end(); ++i2){
  cout<<(*i2)<<endl;
}
vector<int>::iterator found = find(v.begin(), v.end(), 3);
if(found==v.end())
  cout<<"3 is not in v"<<endl;
int a[] = {4, 3, 7, 2, 7};
int* arrfind = find(a, a+5, 5);
if(arrfind==a+5)
  cout<<"5 is not in a"<<endl;

cout<<"max in unordered_set: "<<(*max_element(u.begin(), u.end()))<<endl;
cout<<"max in set: "<<(*max_element(s.begin(), s.end()))<<endl;
    return 0;
vector<int> v2;
copy(v.begin(), v.end(), v2.begin());//Parameters:  start copying from,
//stop copying from, start copying to.
sort(v.begin()+2, v.end());

}





















/*
 *end

 #include <iostream>
 #include <set>
 #include <unordered_set>
 #include <string>
 #include <vector>
 using namespace std;

 int main(int argc, char *argv[])
 {
     set<double> s;//items always stored in sorted order, no duplicates

     s.insert(3.2);
     s.insert(6.2);
     s.insert(1);
     s.insert(5);

     s.insert(1);
     s.insert(5);

     for(auto e:s){//No indices into sets
      cout<<e<<endl;   //can't use [] on sets
     }
 cout<<endl;
      unordered_set<double> u;//not ordered, but still no duplicates
     u.insert(3.2);//In fact, no rhyme or reason to the order they are in!!
     u.insert(6.2);
 u.insert(1.5);
     u.insert(5);

     u.insert(1);
     u.insert(5);

     for(auto e:u){//No indices into sets
      cout<<e<<endl;   //can't use [] on sets
     }


     return 0;
 }

    */
