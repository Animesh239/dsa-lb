// check if the given array is sorted and rotated

#include<iostream>
#include<vector>
using namespace std;

bool isRotSort(vector<int> &nums){

    int count = 0;

    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            count++;
        }
    }

    if(nums[nums.size()-1]>nums[0]){
        count++;
    }

    return count<=1;
}

int main(){

    vector<int> nums = {4,5,6,7,0,1,2};

    cout<<isRotSort(nums)<<endl;

    return 0;
}