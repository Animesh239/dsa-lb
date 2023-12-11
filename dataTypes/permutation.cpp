// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.In other words, return true if one of s1's permutations is the substring of s2.
// example : s1 = "ab" , s2 = "eidbaooo" -> true // "ba" is a permutation of "ab" and is a substring of s2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkEqual(int arr1[26], int arr2[26])
{
    for(int i = 0 ; i < 26; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

bool isPermutation(string s1, string s2)
{
    if(s1.length() > s2.length()){
        return false;
    }

    // character count array
    int count1[26] = {0};
    for(int i = 0 ; i < s1.length(); i++){
        count1[s1[i] - 'a']++;
    }

    // traverse s2 string in a window of length s1.size and compare
    int count2[26] = {0};
    int i = 0;
    int windowSize = s1.length();

    // running the first window
    while(i < windowSize && i < s2.length()){
        count2[s2[i] - 'a']++;
        i++;
    }

    if(checkEqual(count1, count2)){
        return true;
    }
    
    while(i < s2.length()){
        count2[s2[i] - 'a']++;   // add the new character in the window
        count2[s2[i - windowSize] - 'a']--;   // remove the first character from the window
        if(checkEqual(count1, count2)){
            return true;
        }
        i++;
    } 
    return false;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << isPermutation(s1, s2) << endl;
    return 0;
}