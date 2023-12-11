// u are given a string STR and you have to replace all the spaces in the string with "@40" 
// example : "this is a string" -> "this@40is@40a@40string"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string replace_(string str)
{
    string ans = "";
    for(int i = 0 ; i < str.length(); i++){
        if(str[i] == ' '){
            ans += "@40";
        }
        else{
            ans += str[i];
        }
    }
    return ans;
}

int main()
{
    string input = "this is a string";
    cout << replace_(input) << endl;
    return 0;
}