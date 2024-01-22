#include<iostream>
// #include<stack>
using namespace std ;

class Stack{
    public:
        int *arr ;
        int top ;
        int size ;

        Stack(int size){
            this->size = size ;
            arr = new int[size] ;
            top = -1 ;
        }

        void push(int data){
            if(top == size - 1){
                cout << "stack overflow" << endl ;
                return ;
            }
            top++ ;
            arr[top] = data ;
        }

        void pop(){
            if(top == -1){
                cout << "stack underflow" << endl ;
                return ;
            }
            top-- ;
        }

        int peek(){
            if(top == -1){
                cout << "stack underflow" << endl ;
                return -1 ;
            }
            return arr[top] ;
        }

        int length(){
            return top + 1 ;
        }

        bool empty(){
            return top == -1 ;
        }
};

int main(){

    Stack s(5) ;

    s.push(10) ;
    s.push(20) ;
    s.push(30) ;
    s.push(40) ;
    s.push(50) ;

    cout << s.peek() << endl ;
    s.pop() ;
    cout << s.peek() << endl ;

    cout << s.length() << endl ;
    s.empty() ? cout << "stack is empty" << endl : cout << "stack is populated" << endl ;



    return 0 ;
}