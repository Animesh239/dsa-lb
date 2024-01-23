// check for valid parenthesis

#include<iostream>
#include<stack>
using namespace std ;

bool isValid(string &s){
    stack <char>st ;
    for(int i = 0 ;i < s.length() ;i++){
        if(s[i]== '{' || s[i] == '[' || s[i] =='('){
            st.push(s[i]) ;
        }
        else if(s[i] == '}'){
            if(st.empty() || st.top() != '{'){
                return false ;
            }
            st.pop() ;
        }
        else if(s[i] == ']'){
            if(st.empty() || st.top() != '['){
                return false ;
            }
            st.pop() ;
        }
        else if(s[i] == ')'){
            if(st.empty() || st.top() != '('){
                return false ;
            }
            st.pop() ;
        }
    }
    return st.empty() ;
}

int main(){

    string s  = "{([])}" ;
    string s2 = "{([)]}" ;

    cout << isValid(s) << endl ;
    cout << isValid(s2) << endl ;

    return 0 ;
}