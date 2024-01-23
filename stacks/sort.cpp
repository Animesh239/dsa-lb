// sort a stack using recursion

#include<iostream>
#include<stack>
using namespace std ;

void insertAtPosition(stack<int> &stack , int element){
    // base case
    if(stack.empty() || stack.top() <= element){
        stack.push(element) ;
        return ;
    }

    int topElem = stack.top() ;
    stack.pop() ;
    insertAtPosition(stack , element) ;
    stack.push(topElem) ;
}

void sortStack(stack<int> &stack){
    // base case
    if(stack.empty()){
        return ;
    }
    int temp = stack.top() ;
    stack.pop();
    sortStack(stack) ;

    insertAtPosition(stack , temp);
}

int main(){

    stack<int> stack ;

    stack.push(40) ;
    stack.push(20) ;
    stack.push(30) ;
    stack.push(50) ;
    stack.push(10) ;

    sortStack(stack) ;

    while(!stack.empty()){
        cout << stack.top() << " " ;
        stack.pop() ;
    }

    return 0 ;
}