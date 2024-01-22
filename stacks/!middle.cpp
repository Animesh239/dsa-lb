// delete middle elememt from stack

#include<iostream>
#include<stack>
using namespace std ;

void solve(stack<int> &st , int size , int &count){
   // base case
   if(count == size/2){
         st.pop() ;
         return ;
   }
    int temp = st.top() ;
    st.pop() ;
    count++ ;
    solve(st , size , count) ;
    st.push(temp) ;
}   

void deleteMiddle(stack<int> &st , int size){
   int count = 0 ;  
   return solve(st , size , count) ;
}

// other approach without count
void deleteMiddle2(stack<int> &st , int size){
    // base case
    if(st.empty()){
        return ;
    }
    int temp = st.top() ;
    st.pop() ;
    deleteMiddle2(st , size) ;
    if(size % 2 == 0){
        if(st.size() != size/2 - 1){
            st.push(temp) ;
        }
    }else{
        if(st.size() != size/2){
            st.push(temp) ;
        }
    }
}

int main(){

    stack<int> st ;

    st.push(10) ;
    st.push(20) ;
    st.push(30) ;
    st.push(40) ;
    st.push(50) ;
    st.push(60) ;
    // st.push(70) ;

    deleteMiddle(st , st.size() / 2 + 1) ;

    while(!st.empty()){
        cout << st.top() << " " ;
        st.pop() ;
    }

    return 0 ;
}