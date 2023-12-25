// letter combination in a phone number

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string>& ans, string digits, string output, int i, string arr[]) {
    // base case
    if(i>=digits.length()) {
        ans.push_back(output);
        return;
    }

    int number = digits[i]-'0'; // convert char to int from input string]
    string str = arr[number]; // get the corresponding alphabet string from the array

    for(int j=0; j<str.length(); j++) {
        output.push_back(str[j]); // include
        solve(ans, digits, output, i+1, arr); // recursive call
        output.pop_back(); // backtrack
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length()==0) {return ans;}
    string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output = "";
    int i = 0;  // starting index
    solve(ans, digits, output, i, arr);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for(auto i : ans) {
        cout<<i<<" ";
    }
    return 0;
}