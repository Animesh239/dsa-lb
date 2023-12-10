// u are given two arr nums1 and nums2 of size m and n respectively. Both are sorted in non-decreasing order. Merge nums2 into nums1 as one sorted array (non-decreasing order). The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = 0 , j = 0;

    while(i < m && j < n){
        if(nums1[i] <= nums2[j]){
            i++;
        }
        else{
            nums1.insert(nums1.begin()+i,nums2[j]);  // 
            j++;
            i++;
            m++; // why ??  // because we are inserting an element in nums1
        }
    }

   
    while(j < n){
        nums1.insert(nums1.begin()+i,nums2[j]);
        j++;
        i++;
        m++;
    }

  // to remove the extra elements from nums1
    if(nums1.size() > m){ 
// as m increases when we insert an element in nums1; here m = m(previous) + n ;
        nums1.erase(nums1.begin()+m,nums1.end());
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3;
    int n = 3;

    merge(nums1,m,nums2,n);

    cout<<"Merged array is : ";
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    cout<<endl;

    return 0;
}