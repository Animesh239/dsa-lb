// make a matrix using pointers // advantage: no need to pass the size of matrix // dynamic allocation

#include <iostream>
using namespace std;

int main()
{
    // int n ;
    // cin >> n; // size of matrix(n*n)

    // int **arr = new int *[n]; // array of pointers // arr is a pointer to an array of pointers // initialize the first element of every row
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = new int[n]; // initialize the second element of every row // i is the row number
    // }

    // // input
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cin >> arr[i][j];
    //     }
    // }

    // // output
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for mxn matrix

    int m, n;
    cin >> m >> n; // size of matrix(m*n) //m -> rows, n -> columns

    int **arr = new int *[m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // delete the array

    for(int i = 0; i < m; i++){
        delete [] arr[i];
    }

    delete [] arr;


    return 0 ;
}