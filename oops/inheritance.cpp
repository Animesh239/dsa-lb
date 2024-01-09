// different types of inheritance and ambiguity , (single, multiple, multilevel, hybrid, hierarchial,)

#include <iostream>
using namespace std;

class A{
    public:
        void funcA(){
            cout << "funcA" << endl;
        }
};

class B{
    public:
        void funcB(){
            cout << "funcB" << endl;
        }
};

// single inheritance
class C : public A{
    public:
        void funcC(){
            cout << "funcC" << endl;
        }
};

// multiple inheritance
class D : public A, public B{
    public:
        void funcD(){
            cout << "funcD" << endl;
        }
};

// multilevel inheritance
class E : public C{
    public:
        void funcE(){
            cout << "funcE" << endl;
        }
};

// hybrid inheritance
class F : public A{
    public:
        void funcF(){
            cout << "funcF" << endl;
        }
};  

class G : public A, public F{
    public:
        void funcG(){
            cout << "funcG" << endl;
        }
};

// hierarchial inheritance
class H : public A{
    public:
        void funcH(){
            cout << "funcH" << endl;
        }
};

class I : public A{
    public:
        void funcI(){
            cout << "funcI" << endl;
        }
};

// ambiguity
class J : public H, public I{
    public:
        void funcJ(){
            cout << "funcJ" << endl;
        }
};

int main(){

    C c1;
    c1.funcA();
    c1.funcC();

    D d1;
    d1.funcA();
    d1.funcB();
    d1.funcD();

    E e1;
    e1.funcA();
    e1.funcC();
    e1.funcE();

    F f1;
    f1.funcA();
    f1.funcF();

    G g1;
    //g1.funcA();
    g1.funcF();
    g1.funcG();

    H h1;
    h1.funcA();
    h1.funcH();

    I i1;
    i1.funcA();
    i1.funcI();

    //resolve ambiguity
    J j1;
    j1.H::funcA();
    j1.I::funcA();
    j1.funcH();

    return 0;
}