// permutation of an array 

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>>& ans, vector<int>& nums, int i) {
   // base case
    if(i>=nums.size()) {
         ans.push_back(nums);
         return;
    }

    for(int j=i; j<nums.size(); j++) {
        swap(nums[i], nums[j]); // include
        solve(ans, nums, i+1); // recursive call
        swap(nums[i], nums[j]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.size()==0) {return ans;}
    int i = 0;  // starting index
    solve(ans, nums, i);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}