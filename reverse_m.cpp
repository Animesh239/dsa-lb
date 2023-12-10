// an array arr and a position m. Reverse the array after that position.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void reverse_m(vector<int> &arr, int m){
    reverse(arr.begin()+m,arr.end());
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    int m = 5;

    reverse_m(arr,m);

    cout<<"Reversed array is : ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}

// without using algorithm(reverse)

// void reverse_m(vector<int> &arr, int m){
//     int start = m;
//     int end = arr.size()-1;

//     while(start<end){
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;

//         // swap(arr[start],arr[end]);

//         start++;
//         end--;

//     }
// }
