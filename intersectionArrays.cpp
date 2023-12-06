// two arrays with m and n elements respectively. Find the intersection of the two arrays. They are sorted in non-devreasing oreder. return the intersection of the two arraysotherwise -1 if there is no intersection.

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int m;
//     cout << "Enter the length of the first array : ";
//     cin >> m;

//     int arr1[m];
//     for (int i = 0; i < m; i++)
//     {
//         cin >> arr1[i];
//     }

//     int n;
//     cout << "Enter the length of the second array : ";
//     cin >> n;

//     int arr2[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr2[i];
//     }

//     vector<int> ans;

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (arr1[i] == arr2[j])
//             {
//                 ans.push_back(arr1[i]);
//                 arr2[j] = -1;
//                 break;
//             }
//         }
//     }                   
//     return 0;
// }



// optimied solution

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m;
    cout << "Enter the length of the first array : ";
    cin >> m;

    int arr1[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    int n;
    cout << "Enter the length of the second array : ";
    cin >> n;

    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    vector<int> ans;

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return 0;
}