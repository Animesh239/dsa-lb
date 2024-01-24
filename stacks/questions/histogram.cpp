// find the largest rectangular area possible in a given histogram

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElementIndex(vector<int> &arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n,-1); // -1 is the default value in all the 0 to n-1 indices

    for(int i = n-1; i >= 0; i--){
        while(st.top() != -1 && arr[st.top()] >= arr[i]){
            st.pop();
        }
        
        ans[i] = st.top();
        st.push(i); // push the index
    }
    return ans;
}

vector<int> prevSmallerElementIndex(vector<int> &arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n,-1); // -1 is the default value in all the 0 to n-1 indices

    for(int i = 0; i < n; i++){
        while(st.top() != -1 && arr[st.top()] >= arr[i]){
            st.pop();
        }
        
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights){
    int n = heights.size();

    vector<int> left(n), right(n);
    right = nextSmallerElementIndex(heights, n);
    left = prevSmallerElementIndex(heights, n);
    int area = INT16_MIN;

    for(int i = 0; i < n; i++){
        int l = heights[i] ;
        if(right[i] == -1){
            right[i] = n;
        }
        int b = right[i] - left[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}

int main()
{
    vector<int> arr = {2,1,5,6,2,3};
    cout << largestRectangleArea(arr) << endl;
    return 0;
}