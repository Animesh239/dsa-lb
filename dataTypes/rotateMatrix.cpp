// rotate a matrix by 90 degrees

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix)
{
    int nRows = matrix.size();
    int mCols = matrix[0].size();

    // transpose
    for (int i = 0; i < nRows; i++)
    {
        for (int j = i; j < mCols; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < nRows; i++)
    {
        int start = 0;
        int end = mCols - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

// other way to do it : start printing from last column and go to first column and print the elements of that column in reverse order
int rotatedMatrix(vector<vector<int>> &matrix){
    int nRows = matrix.size();
    int mCols = matrix[0].size();
    for(int j = mCols - 1 ; j >= 0 ; j--){
        for(int i = 0 ; i < nRows ; i++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
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
    rotateMatrix(matrix);
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}