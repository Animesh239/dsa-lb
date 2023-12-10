// an arr[] is given . you have to move all the 0's to the end of the arr while maintaining the relative order of the non-zero elements.
// example :  [0,11,0,2,14,0,5] => [11,2,14,5,0,0,0]

#include <iostream>
#include <vector>
using namespace std;

void move0s(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            arr.erase(arr.begin() + i);
            arr.push_back(0);
        }
    }
}

int main()
{
    vector<int> arr = {0, 11, 0, 2, 14, 0, 5};

    move0s(arr);

    cout << "Array after moving 0's to the end is : " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// another solution using two pointers

// void move0s(vector<int> &arr){
//     int i = 0;
//     int j = 0;

//     while(i < arr.size()){
//         if(arr[i] != 0){
//             swap(arr[i],arr[j]);
//             i++;
//             j++;
//         }
//         else{
//             i++;
//         }
//     }
// }

// can also be written using for loop

// void move0s(vector<int> &arr){
//     int j = 0;

//     for(int i = 0; i < arr.size(); i++){
//         if(arr[i] != 0){
//             swap(arr[i],arr[j]);
//             j++;
//         }
//     }
// }