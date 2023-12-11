// spiral print : direction changes after every row or column

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> arr, int nRows, int mCols){
    vector<int> ans;
    int startRow = 0;
    int endRow = nRows - 1;
    int startCol = 0;
    int endCol = mCols - 1;
    while(startRow <= endRow && startCol <= endCol){
        // print start row
        for(int j = startCol ; j <= endCol ; j++){
            ans.push_back(arr[startRow][j]);
        }
        startRow++;
        // print end col
        for(int i = startRow ; i <= endRow ; i++){
            ans.push_back(arr[i][endCol]);
        }
        endCol--;
        // print end row
        if(endRow >= startRow){
            for(int j = endCol ; j >= startCol ; j--){
                ans.push_back(arr[endRow][j]);
            }
            endRow--;
        }
        // print start col
        if(endCol >= startCol){
            for(int i = endRow ; i >= startRow ; i--){
                ans.push_back(arr[i][startCol]);
            }
            startCol++;
        }
    }
    return ans;
}

int main(){
    int nRows, mCols;
    cin >> nRows >> mCols;
    vector<vector<int>> arr(nRows, vector<int>(mCols));
    for(int i = 0 ; i < nRows ; i++){
        for(int j = 0 ; j < mCols ; j++){
            cin >> arr[i][j];
        }
    }
    vector<int> ans = spiralPrint(arr, nRows, mCols);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}