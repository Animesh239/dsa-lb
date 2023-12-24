// given an array, return the power set using recursion

#include<iostream>
#include<vector>
using namespace std ;

vector<vector<int>> subset(vector<int> arr, int index){
    vector<vector<int>> allsubsets ;
    if(arr.size() == index){
        allsubsets.push_back({}) ;
    }
    else{
        allsubsets = subset(arr, index+1) ;
        int item = arr[index] ;
        vector<vector<int>> moresubsets ;
        for(auto subset: allsubsets){
            vector<int> newsubset(subset) ;
            newsubset.push_back(item) ;
            moresubsets.push_back(newsubset) ;
        }
        for(auto subset: moresubsets){
            allsubsets.push_back(subset) ;
        }
    }
    return allsubsets ;
}

int main(){
    vector<int> arr = {1,2,3,4} ;

    vector<vector<int>> allsubsets = subset(arr, 0) ;
    for(auto subset: allsubsets){
        for(auto item: subset){
            cout << item << " " ;
        }
        cout << endl ;
    }


    return 0;
}