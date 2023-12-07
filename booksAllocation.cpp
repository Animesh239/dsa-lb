// books allocation to students such that each student gets atleast one book and find the maximum number of pages allocated which is minimum among possible allocations.

#include <iostream>
using namespace std;

bool isPossibleSolution(int arr[], int students, int books, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0 ; i < books ; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if(studentCount > students || arr[i] > mid){
                return false;
            }
            // pageSum = 0 ;
            // pageSum += arr[i]; 
            // same as above
            pageSum = arr[i];
        }
    }
    return true;
}

int findMininmumOfAllMaximum(int arr[], int students , int books){
    int s = 0;
    int sum = 0; 
    for(int i=0 ; i < books ; i++){
        sum += arr[i];
    }
    int e = sum; // total number of pages in all books
    int ans = -1 ;
    int mid = s + (e - s) / 2;


    while(s<=e){
        mid = s + (e - s) / 2;
        if(isPossibleSolution(arr, students, books, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}



int main(){

    int arr[7] = {2,2,3,3,4,4,1} ;  // 4 students and 7 books and each element of array is the number of pages in each book

    int students = 4 ;
    int books = 7 ;

    cout << findMininmumOfAllMaximum(arr, students, books) << endl;

    return 0;
}