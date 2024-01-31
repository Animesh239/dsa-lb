//  N Stacks In An Array

#include <iostream>
#include <vector>
using namespace std;

class Nstack{
    private:
        int *arr ;
        int *top ;
        int *next ;

        int n , s ;

        int freespot ;

    public:
        Nstack(int N , int S){
            n = N ; // number of stacks
            s = S ; // size of array

            arr = new int[s] ;
            top = new int[n] ;
            next = new int[s] ;

            // initialize top array with -1
            for(int i = 0 ; i < n ; i++){
                top[i] = -1 ;
            }

            // initialize freespot with 0
            freespot = 0 ;
            
            // initialize next array        
            for(int i = 0 ; i < s - 1 ; i++){
                next[i] = i + 1 ;
            }
            // last element of next array is -1
            next[s - 1] = -1 ;
        }

        // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
        bool push(int x, int m)
        {
            // check for overflow
            if(freespot == -1){
                return false ;
            }

            // find index through freespot
            int index = freespot ;

            // update freespot
            freespot = next[index] ;

            // insert element in the array
            arr[index] = x ;

            // update next array
            next[index] = top[m-1] ;

            // update top array
            top[m-1] = index ;

            return true ;
        }

        // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
        int pop(int m)
        {
            // check for underflow
            if(top[m-1] == -1){
                return -1 ;
            }

            // find index through top array
            int index = top[m-1] ;

            // update top array
            top[m-1] = next[index] ;

            // update next array
            next[index] = freespot ;

            // update freespot
            freespot = index ;

            // return the element
            return arr[index] ;
        }
};