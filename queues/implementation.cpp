// create a class queue using arrays and implement the following functions : pop(), push(), front(), empty(), size()

#include<iostream>
using namespace std;

class queue{
    int *arr;
    int f; // index of the first element(the element which will be removed first /  the element which is at the front )
    int back; // index of the last element
    int n;
    int capacity;

    public:
    queue(int size){
        arr = new int[size] ;
        f = 0 ;
        back = 0 ;
        n= 0 ;
        capacity = size ;
    }

    void push(int x){
        if(n == capacity){
            cout << "Queue Overflow" << endl ;
            return ;
        }
        n++ ;
        arr[back] = x ;
        back++ ;
    }

    void pop(){
        if(n == 0){
            cout << "Queue Underflow" << endl ;
            return ;
        }
        f++ ;
        n-- ;
        // back to 0th index
        if(f == back){
            f = 0 ;
            back = 0 ;
        }
    }

    int front(){
        if(n == 0){
            cout << "Queue Underflow" << endl ;
            return -1 ;
        }
        return arr[f] ;
    }

    bool empty(){
        return n == 0 ;
    }

    int size(){
        return n ;
    }
};

void print(queue q){
    while(!q.empty()){
        cout << q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;
}

int main(){
    queue q(6) ;
    q.push(10) ;
    q.push(20) ;
    q.push(30) ;
    q.push(40) ;
    q.push(50) ;
    q.push(60) ;
    print(q) ;
    cout << q.front() << endl ;
    q.pop() ;
    cout << q.front() << endl ;
    cout << q.size() << endl ;
    cout << q.empty() << endl ;
    return 0 ;
}