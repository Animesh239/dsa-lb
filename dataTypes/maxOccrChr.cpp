// get the maximum occuring character in a string

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char getMaxOccrChar(string str)
{
    int count[26] = {0};

    for(int i = 0 ; i < str.length(); i++){
        int number  = 0 ;
        if(str[i] >= 'a' || str[i] <= 'z'){
            number = str[i]  -'a' ;
        }
        else if(str[i] >= 'A' || str[i] <= 'Z'){
            number = str[i]  -'A' ;
        }
        count[number]++ ;
    }

    int maxIndex = 0 ;
    for(int i = 0 ; i < 26; i++){
        maxIndex = count[i] > count[maxIndex] ? i : maxIndex ;
    }

    char ans = 'a' + maxIndex ;
}




int main()
{
    char input[] = "bbbbddbbbeeeeeeeeeeeeeeeeeee";
    cout << getMaxOccrChar(input) << endl;
    return 0;
}