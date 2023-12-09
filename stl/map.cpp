// props of map: 1. sorted by key 2. unique key 3. key cannot be modified

#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int , string > m;

    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    m.insert(pair<int, string>(4, "four"));

    for(auto i : m)
        cout << i.first << " " << i.second  << endl;

    // count gives 0 or 1
    // find gives iterator
    // lower_bound gives iterator
    // upper_bound gives iterator

    cout << "after erase : " << endl;
    m.erase(3);
    for(auto i : m)
        {cout << i.first << " " << i.second  << endl;}

    //iterator
    auto it = m.find(4);
    for(auto i = it ; i != m.end(); i++)
        {cout << (*i).first << " " << (*i).second  << endl;}

    return 0;
}