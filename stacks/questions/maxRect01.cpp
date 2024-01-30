// find the area of the largest rectangle in a binary matrix

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElementIndex(int *arr, int n){
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

vector<int> prevSmallerElementIndex(int *arr, int n){
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

int largestRectangleArea(int *heights, int n){
    // int n = heights.size();

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

// n is the number of rows and m is the number of columns
int maxArea(int M[INT16_MAX][INT16_MAX] , int n, int m){

    // compute area of forst row
    int area = largestRectangleArea(M[0], m);

    // compute area for remaining rows
    for(int i =1 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
           if(M[i][j] == 1){
            // adding the previous row to the current row
               M[i][j] += M[i-1][j];
           }else{
                M[i][j] = 0 ;
           }
        }
        area = max(area , largestRectangleArea(M[i] , m)) ;
    }
    return area ;
}

int main()
{
    int M[INT16_MAX][INT16_MAX] = {{0, 1, 1, 0},
                                   {1, 1, 1, 1},
                                   {1, 1, 1, 1},
                                   {1, 1, 0, 0}};
    int n = 4, m = 4;
    cout << maxArea(M, n, m) << endl;
    return 0;
}