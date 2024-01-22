// operations to two stacks initialized from a single array

#include <iostream>
using namespace std;

class TwoStack{
    private:
        int size;
        int *arr;
        int top1;
        int top2;
    public:
       TwoStack(int size){
           this->size = size;
           arr = new int[size];
           top1 = -1;
           top2 = size;
       }

         void push1(int num){
              if(top1 == top2 - 1){
                cout << "stack overflow" << endl;
                return;
              }
              top1++;
              arr[top1] = num;
         }

            void push2(int num){
                if(top1 == top2 - 1){
                    cout << "stack overflow" << endl;
                    return;
                }
                top2--;
                arr[top2] = num;
            }

            int pop1(){
                if(top1 >= 0){
                    int ans = arr[top1];
                    top1--;
                    return ans;
                }else{
                    return -1 ;
                }
            }

            int pop2(){
                if(top2 < size){
                    int ans = arr[top2];
                    top2++;
                    return ans;
                }else{
                    return -1 ;
                }
            }
} ;

int main(){
    TwoStack s(5);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);

    s.push2(100);
    s.push2(200);
    s.push2(300);
    s.push2(400);
    s.push2(500);

    s.pop1();
    s.pop2();

    return 0;
}