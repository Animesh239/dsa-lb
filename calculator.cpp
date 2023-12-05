#include<iostream>   
#include<cmath> // for power function
using namespace std;

int main(){
    int a, b;
    char op;

    cout << "Enter first number a : " << endl ;
    cin >> a;

    cout << "Enter second number b : " << endl ;
    cin >> b;

    cout << "Enter operator( + , - , * , / , % ) : " << endl ;
    cin >> op;

    switch(op){
        case '+':
            cout << "a + b = " << a + b << endl;
            break;
        case '-':
            cout << "a - b = " << a - b << endl;
            break;
        case '*':
            cout << "a * b = " << a * b << endl;
            break;
        case '/':
            cout << "a / b = " << a / b << endl;
            break;
        case '%':
            cout << "a % b = " << a % b << endl;
            break;
        default:
            cout << "Invalid operator" << endl;
    }


    return 0;
}