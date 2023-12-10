#include <iostream>
using namespace std;

// length of string
int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// reverse a string
void reverse(char input[])
{
    int len = length(input);
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        swap(input[start++], input[end--]);
    }
}

// to lowercase
char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch - 'A' + 'a'; // or input[i] = input[i] + 32; // 'a' = 97 and 'A' = 65
    }
    return ch;
}

// check palindrome
bool isPalindrome(char input[])
{
   int len = length(input);
    int start = 0;
    int end = len - 1;

   // check valid characters -> tolower -> compare
    while (start < end)
    {
        if (!isValid(input[start]))
        {
            start++;
        }
        else if (!isValid(input[end]))
        {
            end--;
        }
        else if (toLower(input[start++]) != toLower(input[end--]))
        {
            return false;
        }
    }
    return true;


}

// valid character
bool isValid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ) // or (ch >= '0' && ch <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{

    char input[100];
    cout << "Enter a string : ";
    cin.getline(input, 100);

    cout << "Length of string is : " << length(input) << endl;

    reverse(input);

    cout << "Reversed string is : " << input << endl;

    if (isPalindrome(input))
    {
        cout << "String is a palindrome" << endl;
    }
    else
    {
        cout << "String is not a palindrome" << endl;
    }

    return 0;
}