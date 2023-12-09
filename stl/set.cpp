// properties of set

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);


    cout << "size: " << s.size() << endl;
    cout << "max_size: " << s.max_size() << endl;
    cout << "empty: " << s.empty() << endl;

    cout << "begin: " << *s.begin() << endl;
    cout << "end: " << *s.end() << endl;

    cout << "count: " << s.count(3) << endl;  // Number of elements with specified key. This function only makes sense for multisets; for set the result will either be 0 (not present) or 1 (present)
    cout << "find: " << *s.find(4) << endl;
    cout << "lower_bound: " << *s.lower_bound(2) << endl;
    cout << "upper_bound: " << *s.upper_bound(2) << endl;

    cout << "erase 3: " << endl;
    s.erase(3);
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << "clear: " << endl;
    s.clear();
    cout << "size: " << s.size() << endl;

    return 0;
}