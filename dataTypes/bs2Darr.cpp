// search a target in a 2D matrixay using binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchIn2D(vector<vector<int>> matrix, int target)
{
    int mRows = matrix.size();
    int nColumns = matrix[0].size();

    int start = 0;
    int end = mRows * nColumns - 1;

    int mid = start + (end - start) / 2;

    
    while(start <= end){
        mid = start + (end - start) / 2;

        int rowIndex = mid / nColumns;
        int colIndex = mid % nColumns;

        if(matrix[rowIndex][colIndex] == target){
            return 1 ;
        }
        else if(matrix[rowIndex][colIndex] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0 ;
}

int main()
{
    int nRows, mCols;
    cin >> nRows >> mCols;
    vector<vector<int>> matrix(nRows, vector<int>(mCols));
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int target;
    cin >> target;
    cout << searchIn2D(matrix, target);
    return 0;
}