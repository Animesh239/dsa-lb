// runtime polymorphism

#include <iostream>
using namespace std;

class Parent{
    public:
        void show(){
            cout << "inside Parent class" << endl;
        }
};

class subClass1 : public Parent{
    public:
        void show(){
            cout << "inside subClass1" << endl;
        }
};  

class subClass2 : public Parent{
    public:
        void show(){
            cout << "inside subClass2" << endl;
        }
};

int main(){

    subClass1 s1;
    subClass2 s2;

    s1.show();
    s2.show();

    return 0 ;
}



