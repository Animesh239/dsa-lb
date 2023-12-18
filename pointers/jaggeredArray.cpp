// jaggered array

#include <iostream>
using namespace std;

int main(){
    int m ;
    cin >> m; // number of rows

    // int sizes[3] = {2, 3, 4}; // number of columns in each row

    // allocating sizes[] dynamically
    int *sizes = new int[m];
    for(int i = 0; i < m; i++){
        cin >> sizes[i];
    }

    int **arr = new int *[m]; 

    for(int i = 0; i < m; i++){
        arr[i] = new int[sizes[i]];
    }

    // input
    for(int i = 0; i < m; i++){
        for(int j = 0; j < sizes[i]; j++){
            cin >> arr[i][j];
        }
    }

    // output
    for(int i = 0; i < m; i++){
        for(int j = 0; j < sizes[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // delete the array


    for(int i = 0; i < m; i++){
        delete [] arr[i];
    }

    return 0;

}