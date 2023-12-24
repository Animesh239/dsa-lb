// find all the subsequence of a string using recursion

#include<iostream>
#include<vector>
using namespace std ;

vector<string> subsequence(string str, int index){
    vector<string> allsubsequence ;
    if(str.size() == index){
        allsubsequence.push_back("") ;
    }
    else{
        allsubsequence = subsequence(str, index+1) ;
        char item = str[index] ;
        vector<string> moresubsequence ;
        for(auto subsequence: allsubsequence){
            string newsubsequence = subsequence ;
            newsubsequence.push_back(item) ;
            moresubsequence.push_back(newsubsequence) ;
        }
        for(auto subsequence: moresubsequence){
            allsubsequence.push_back(subsequence) ;
        }
    }
    return allsubsequence ;
}

int main(){
    string str = "abc" ;

    vector<string> allsubsequence = subsequence(str, 0) ;
    for(auto subsequence: allsubsequence){
        cout << subsequence << endl ;
    }

    return 0;
}