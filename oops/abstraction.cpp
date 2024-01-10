// abstraction

#include <iostream>
using namespace std;

class abstraction{
    private:
        int a;
        int b;

    public:
        void setData(int a, int b){
            this->a = a;
            this->b = b;
        }

        void getData(){
            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
        }
};

int main(){

    abstraction a1;
    a1.setData(10, 20);
    a1.getData();

    return 0 ;
}

// differenvce in abstraction and encapsulation
// abstraction: hiding the internal details and showing the functionality
// encapsulation: binding together the data and functions that manipulate them