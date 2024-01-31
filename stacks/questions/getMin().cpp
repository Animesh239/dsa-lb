// Design a stack that supports getMin() in O(1) time and O(1) extra space
// for space complexity O(1) we will use a variable

#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {

    private:
        stack<int> s;
        int mini;

    public:
        
    void push(int data) {
        // for first element
        if(s.empty()){
            s.push(data);
            mini = data;
        }else{
            // if data is greater than mini
            if(data >= mini){
                s.push(data);
            }else{
                // if data is less than mini
                s.push(2*data - mini);  // 2*data - mini is less than data and mini, so we push a value less than mini so that we can retrieve mini
                mini = data;
            }
        }
    }

    void pop() {
        // if stack is empty
        if(s.empty()){
            return;
        }
        // if top element is greater than mini
        if(s.top() >= mini){
            s.pop();
        }else{
            // if top element is less than mini
            mini = 2*mini - s.top();
            s.pop();
        }

    }

    int top() {
        // if stack is empty
        if(s.empty()){
            return -1;
        }
        // if top element is greater than mini
        if(s.top() >= mini){
            return s.top();
        }else{
            // if top element is less than mini
            return mini;
        }
    }

    int getMin() {
        // if stack is empty
        if(s.empty()){
            return -1;
        }
        return mini;
    }  
};