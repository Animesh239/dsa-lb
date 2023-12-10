// you are given an nums and a number k. Rotate the nums k steps to the right.

// example : nums = [1,2,3,4,5,6,7] , k = 3 => [5,6,7,1,2,3,4]

// void rotate_k(vector<int> &nums, int k){
//     reverse(nums.begin(),nums.end());
//     reverse(nums.begin(),nums.begin()+k);
//     reverse(nums.begin()+k,nums.end());
// }

// int main(){

//     vector<int> nums = {1,2,3,4,5,6,7};

//     int k = 3;

//     rotate_k(nums,k);

//     cout<<"Rotated numsay is : ";
//     for(int i=0;i<nums.size();i++){
//         cout<<nums[i]<<" ";
//     }
//     cout<<endl;

//     return 0;

// }

// without using algorithm(reverse)



// void rotate_k(vector<int> &nums, int k){
//     int start = 0;
//     int end = nums.size()-1;

//     while(start<end){
//         int temp = nums[start];
//         nums[start] = nums[end];
//         nums[end] = temp;

//         // swap(nums[start],nums[end]);

//         start++;
//         end--;

//     }

//     start = 0;
//     end = k-1;

//     while(start<end){
//         int temp = nums[start];
//         nums[start] = nums[end];
//         nums[end] = temp;

//         // swap(nums[start],nums[end]);

//         start++;
//         end--;

//     }

//     start = k;
//     end = nums.size()-1;

//     while(start<end){
//         int temp = nums[start];
//         nums[start] = nums[end];
//         nums[end] = temp;

//         // swap(nums[start],nums[end]);

//         start++;
//         end--;

//     }
// }


// most optimized solution


#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &nums,int k){

   vector<int> temp(nums.size());

   for(int i = 0 ; i < nums.size(); i++){
       temp[(i+k)%nums.size()] = nums[i];
   }

   nums = temp;
}
