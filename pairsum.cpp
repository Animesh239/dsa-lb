// you are given an array of n integers and an integer s. You have to find all the pairs whose sum = s.

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pairSum(vector<int> arr, int s)
{
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    // sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s;
    cout << "Enter the sum : ";
    cin >> s;

    vector<vector<int>> ans = pairSum(arr, s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    
    return 0;
}