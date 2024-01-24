// find the next smaller element in an array

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n,-1); // -1 is the default value in all the 0 to n-1 indices

    for(int i = n-1; i >= 0; i--){
        while(st.top() != -1 && st.top() >= arr[i]){
            st.pop();
        }
        
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> ans = nextSmallerElement(arr, arr.size());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}