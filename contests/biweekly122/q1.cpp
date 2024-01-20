// 3010. Divide an Array Into Subarrays With Minimum Cost I

// You are given an array of integers nums of length n.

// The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

// You need to divide nums into 3 disjoint contiguous 
// subarrays
// .

// Return the minimum possible sum of the cost of these subarrays.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCost(vector<int> &nums){
    int n = nums.size() ;
    int minSum = INT16_MAX ;
    for(int i= 1 ; i< n ; i++){
        int sum = nums[i] ;
        for(int j = i+1 ; j < n ; j++){
            minSum = min(minSum , sum+nums[j]) ;
        }
    }
    return nums[0] + minSum ;
}

int minCost2(vector<int> &nums){
    sort(nums.begin()+1 , nums.end()) ;
    return nums[0] + nums[1] + nums[2] ;
}


// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/