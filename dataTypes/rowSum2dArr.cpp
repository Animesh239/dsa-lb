// give the row wise sum of a 2d array

// also give the index of largest row sum and its value

#include <iostream>
#include <climits>
using namespace std;

// row wise sum
void rowSum(int arr[][100], int row, int column){
    for(int i = 0 ; i < row ; i++){
        int sum = 0;
        for(int j = 0 ; j < column ; j++){
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

// index of largest row sum
void largestRowSum(int arr[][100], int row, int column){
    int maxSum = INT_MIN;
    int maxIndex = 0;
    for(int i = 0 ; i < row ; i++){
        int sum = 0;
        for(int j = 0 ; j < column ; j++){
            sum += arr[i][j];
        }
        if(sum > maxSum){
            maxSum = sum;
            maxIndex = i;
        }
    }
    cout << maxIndex << " " << maxSum << endl;
}

int main(){
    
    int arr[100][100];
    int row, column;
    cin >> row >> column;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            cin >> arr[i][j];
        }
    }
    rowSum(arr, row, column);
    cout << endl;
    largestRowSum(arr, row, column);
    return 0;
}