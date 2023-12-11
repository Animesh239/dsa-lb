// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed: Find the leftmost occurrence of the substring part and remove it from s. Return s after removing all occurrences of part.
// example : s= "daabcbaabcbc" , part = "abc" -> "dab"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string remove_substring(string str, string part)
{
    while(str.length() != 0 && str.find(part) < str.length()){
        str.erase(str.find(part), part.length());
    }
    return str;
}

int main()
{
    string input = "daabcbaabcbc";
    string part = "abc";
    cout << remove_substring(input, part) << endl;
    return 0;
}