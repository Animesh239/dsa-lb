// an array with n elememts. find all the triplets whose sum is equal to s.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tripletSum(vector<int> arr, int s)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int j = i + 1;
        int k = arr.size() - 1;
        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] == s)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
                ans.push_back(temp);
                j++;
                k--;
            }
            else if (arr[i] + arr[j] + arr[k] > s)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}

int main(){
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

    vector<vector<int>> ans = tripletSum(arr, s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
    
    return 0;
}