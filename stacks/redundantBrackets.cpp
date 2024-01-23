// find redundant brackets in a given expression

#include <iostream>
#include <stack>
using namespace std;

bool redundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                return true;
            }
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
            {
                st.pop();
            }
            st.pop();
        }
    }
    return false;
}

int main()
{

    string s = "((a+b))";
    string s2 = "(a+(b)/c)";
    string s3 = "(a+b*(c-d))";
    string s4 = "(a+b*(c-d))";

    cout << redundantBrackets(s) << endl;
    cout << redundantBrackets(s2) << endl;
    cout << redundantBrackets(s3) << endl;
    cout << redundantBrackets(s4) << endl;

    return 0;
}