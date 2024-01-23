// reverse a stack using recursion

#include<iostream>
#include<stack>
using namespace std ;

void insertAtBottom(int temp , stack<int> &stack) {
    // base case
    if(stack.empty()){
        stack.push(temp) ;
        return ;
    }
    int val = stack.top() ;
    stack.pop() ;
    insertAtBottom(temp , stack) ;
    stack.push(val) ;
}

void reverseStack(stack<int> &stack) {
 // base case
    if(stack.empty()){
        return ;
    }
    int temp = stack.top() ;
    stack.pop() ;
    reverseStack(stack) ;
    insertAtBottom(temp , stack) ;
}

int main(){

    stack<int> stack ;

    stack.push(10) ;
    stack.push(20) ;
    stack.push(30) ;
    stack.push(40) ;
    stack.push(50) ;

    reverseStack(stack) ;

    while(!stack.empty()){
        cout << stack.top() << " " ;
        stack.pop() ;
    }

    return 0 ;
}

