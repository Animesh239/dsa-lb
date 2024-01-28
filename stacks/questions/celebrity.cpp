// identify the celebrity in a party : celebrity is a person who knows no one but everyone knows him/her

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // push all the indices in the stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    // pop two elements and compare them
    while(st.size() >= 2){
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();

        if(M[i][j] == 1 && M[j][i] == 0){
            // i knows j and j doesn't know i, so j "can" be a celebrity
            st.push(j);
        }else{
            // i doesn't know j and j knows i, so i "can" be a celebrity
            st.push(i);
        }
    }
    // check if the last element in the stack is a celebrity
    int celeb = st.top();
    for(int i = 0; i < n; i++){
        if(i != celeb){
            if(M[i][celeb] == 0 || M[celeb][i] == 1){
                return -1;
            }
        }
    }
    return celeb;
}

int main()
{
    vector<vector<int>> M = {{0, 0, 1, 0},
                             {0, 0, 1, 0},
                             {0, 0, 0, 0},
                             {0, 0, 1, 0}};
    int n = 4;
    cout << celebrity(M, n) << endl;
    return 0;
}