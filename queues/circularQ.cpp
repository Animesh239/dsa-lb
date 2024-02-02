// Description: Circular Queue implementation using array.

#include<iostream>
using namespace std;

class CircularQueue{
    int *arr ;
    int queueFront ;
    int queueBack ;
    int capacity ;
    int n ;

    public:
       CircularQueue(int n){
        arr = new int[n] ;
        queueFront = 0 ;
        queueBack = 0 ;
        capacity = n ;
        n = 0 ;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(n == capacity){
            return false ;
        }
        arr[queueBack] = value ;
        queueBack = (queueBack + 1) % capacity ;
        n++ ;
        return true ;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(n == 0){
            return -1 ;
        }
        int x = arr[queueFront] ;
        queueFront = (queueFront + 1) % capacity ;
        n-- ;
        return x ;
    }

    bool empty(){
        return n == 0 ;
    }
};

void printQueue(CircularQueue q){
    while(!q.empty()){
        cout << q.dequeue() << " " ;
    }
    cout << endl ;
}