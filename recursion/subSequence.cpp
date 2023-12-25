#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Function to generate all subsequences of a string
vector<string> generateSubsequences(string str, int index) {
    vector<string> subsequences;

    // Base case: if we've reached the end of the string, return an empty subsequence
    if(index == str.size()) {
        subsequences.push_back("");
        return subsequences;
    }

    // Recursive case: generate all subsequences for the rest of the string
    subsequences = generateSubsequences(str, index + 1);

    // Get the current character
    char currentChar = str[index];

    // Create a new list to store subsequences that include the current character
    vector<string> newSubsequences;

    // Add the current character to each subsequence
    for(auto subsequence : subsequences) {
        string newSubsequence = subsequence;
        newSubsequence.push_back(currentChar);
        newSubsequences.push_back(newSubsequence);
    }

    // Add the new subsequences to the list of all subsequences
    subsequences.insert(subsequences.end(), newSubsequences.begin(), newSubsequences.end());

    return subsequences;
}

int main() {
    string str = "abc";
    vector<string> allSubsequences = generateSubsequences(str, 0);

    // Print all subsequences
    for(auto subsequence : allSubsequences) {
        cout << subsequence << endl;
    }

    return 0;
}