// mxn matrix in which each row and column is sorted in ascending order. search for a target in this matrix using bs

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchIn2D(vector<vector<int>> matrix, int target)
{
    int mRows = matrix.size();
    int nColumns = matrix[0].size();

    pair<int,int> start = {0,0};
    pair<int,int> end = {mRows - 1, nColumns - 1};

    while(start.first <= end.first && start.second <= end.second){
        if(matrix[start.first][end.second] == target){
            return 1;
        }
        else if(matrix[start.first][end.second] < target){
            start.first++;
        }
        else{
            end.second--;
        }
    }
    return 0;
}

// can also be written without using pair
bool searchIn2D_2(vector<vector<int>> matrix, int target)
{
    int mRows = matrix.size();
    int nColumns = matrix[0].size();

    int rowIndex = 0;
    int columnIndex = nColumns - 1;

    while(rowIndex < mRows && columnIndex >= 0){
        if(matrix[rowIndex][columnIndex] == target){
            return 1;
        }
        else if(matrix[rowIndex][columnIndex] < target){
            rowIndex++;
        }
        else{
            columnIndex--;
        }
    }
    return 0;
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