// compression of string
// Given an array of characters chars, compress it using the following algorithm:
// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
// After you are done modifying the input array, return the new length of the array.
// You must write an algorithm that uses only constant extra space.
// example : "aaabbbcccd" -> "a3b3c3d"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int compress(vector<char>& chars)
// {
//     // count array
//     int count[26] = {0};
//     for(int i = 0 ; i < chars.size(); i++){
//         count[chars[i] - 'a']++;
//     }
//     // compressing the string -> 4 cases :  count = 0, count = 1, 1 < count < 9, count > 9
//     int i = 0;
//     int j = 0;
//     while(i < 26){
//         if(count[i] == 0){
//             i++;
//             continue;
//         }
//         else if(count[i] == 1){
//             chars[j] = 'a' + i;
//             j++;
//         }
//         else if(count[i] > 1 && count[i] < 10){
//             chars[j] = 'a' + i;
//             j++;
//             chars[j] = '0' + count[i];
//             j++;
//         }
//         else{
//             chars[j] = 'a' + i;
//             j++;
//             chars[j] = '0' + count[i] / 10;
//             j++;
//             chars[j] = '0' + count[i] % 10;
//             j++;
//         }
//         i++;
//     }
//     return j;
// }

int compress(vector<char>& chars){
    int i = 0; 
    int n = chars.size();
    int ansindex = 0 ;

    while(i < n){
        int j = i + 1 ;
        while(j < n && chars[j] == chars[i]){
            j++;
        }
        // chars[ansindex] = chars[i];
        // ansindex++;
        chars[ansindex++] = chars[i];

        int count = j - i ;

        if(count > 1){
            // convertig the count into single digits as strings
            string cnt = to_string(count);
            for( char ch : cnt){
                chars[ansindex++] = ch;
               // chars[ansindex] = ch ; ansindex++ ;
            }
        }
        i = j ; // i goes to the next character as j is the next character
    }
    return ansindex;
}

int main()
{
    vector<char> input = {'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'd'};
    cout << compress(input) << endl;
    return 0;
}