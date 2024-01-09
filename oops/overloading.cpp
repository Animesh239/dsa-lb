// operator overloading

#include <iostream>
using namespace std;

class B{

    public:
        int a;
        int b;

    void operator+ (B &obj){
        cout << "operator overloading" << endl;
        cout << this->a - obj.a << endl;
    }
};

int main(){

    B b1, b2;
   
    b1.a = 10;
    b2.a = 20;

    b1 + b2;  // b1.+(b2)

    return 0;
}