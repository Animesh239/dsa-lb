// find the minimum cost to make the STR valid

#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    if (str.length() % 2 != 0)
    {
        return -1;
    }

    stack<char> st;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            st.push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (st.empty())
            {
                count++;
                st.push('{');
            }
            else
            {
                st.pop();
            }
        }
    }
    return count + st.size() / 2;
}

int main()
{

    string str = "}}{{" ;

    cout << findMinimumCost(str) << endl;

    return 0;
}