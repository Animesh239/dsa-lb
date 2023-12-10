// reverse words in a string (words are separated by space)
// example: "welcome to coding ninjas" -> "ninjas coding to welcome"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseWords(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        swap(s[start++], s[end--]);
    }

    start = 0;
    end = 0;

    while (end <= s.size())
    {
        if (s[end] == ' ' || end == s.size()) // end == s.size() is for the last word
        {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        end++;
    }

    // reverse(s.begin() + start, s.begin() + end);
}

int main()
{
    vector<char> s = {'w', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o', ' ', 'c', 'o', 'd', 'i', 'n', 'g', ' ', 'n', 'i', 'n', 'j', 'a', 's'};
    reverseWords(s);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}