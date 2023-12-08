// There is an unsorted arr of N elements each representing the position of a stall. There are K no. of cows that need to be placed in the stalls. Find the largest minimum distance between the cows.

#include<iostream>
using namespace std ;

bool isPossible(int arr[] , int n , int k , int mid){
    int cows = 1 ;
    int pos = arr[0] ;

    for(int i=0 ; i < n ; i++){
        if(arr[i] - pos >= mid){
            cows++;
            pos = arr[i];
        }
        if(cows == k){
            return true;
        }
    }
    return false;
}

int findLargestMinDistance(int arr[] , int n , int k){
    int s = 0 ;
    int maxi = 0 ;
    for(int i=0 ; i < n ; i++){
        maxi = max(maxi , arr[i]) ;
    }
    int e = maxi ;
    int ans = -1 ;
    int mid = s + (e - s) / 2 ;

    while(s<=e){
        mid = s + (e - s) / 2 ;
        if(isPossible(arr, n , k , mid)){
            ans = mid ;
            s = mid + 1 ;
        }
        else{
            e = mid - 1 ;
        }
    }
    return ans ;
}

int main(){
    int arr[6] = {0,3,4,7,10,9} ;
    int n = 6 ;
    int k = 4 ;

    cout << findLargestMinDistance(arr, n , k) << endl;
}
