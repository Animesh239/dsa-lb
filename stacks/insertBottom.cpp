// insert an element in the stack at the bottom

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& myStack, int x) {
    if(myStack.empty()) {
        myStack.push(x);
        return;
    }
    int temp = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(temp);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}

int main() {

    stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    myStack = pushAtBottom(myStack, 60);

    while(!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}