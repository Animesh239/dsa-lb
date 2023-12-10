// u are given two arrays arr1 and arr2 of size n and m respectively. Each element of an array represents each digit of the number. U have to find the sum of both the numbers represented by the arrays. Return the sum in the form of an array.

// example : arr1 = {1,2,3} and arr2 = {2,3,4} then the sum is 123 + 234 = 357 and the resultant array is {3,5,7}

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<int> sumOfTwoArrays(vector<int> &arr1, int n, vector<int> &arr2, int m){

    int num1 = 0;
    for(int i=0;i<n;i++){
        num1 = num1*10 + arr1[i];
    }
    int num2 = 0;
    for(int i=0;i<m;i++){
        num2 = num2*10 + arr2[i];
    }

    int sum = num1 + num2;

    // deque<int> dq;
    // while(sum>0){
    //     int rem = sum%10;
    //     dq.push_front(rem);
    //     sum = sum/10;
    // }

    // vector<int> ans;

    // while(!dq.empty()){
    //     ans.push_back(dq.front());
    //     dq.pop_front();
    // }

    vector<int> ans;    
    while(sum>0){
        int rem = sum%10;
        ans.push_back(rem);
        sum = sum/10;
    }

    reverse(ans.begin(),ans.end());

    return ans;

}

int main(){

    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {2,3,4};

    vector<int> ans = sumOfTwoArrays(arr1,arr1.size(),arr2,arr2.size());

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}