// intro to class , public and private , getters and setters, use of pointers

#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    int price;

public:
    int model;
    char *name;

    // constructor
    Car()
    {
        cout << "Inside Car Constructor" << endl;
    }

    // parameterized constructor
    Car(int price, int model, char *name)
    {
        cout << "Inside Parameterized Constructor" << endl;
        this->price = price;  // "this" is a keyword which points to the object which is calling the function
        this->model = model;
        // this->name = name; // shallow copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // copy constructor
    // Car(Car &X)   
    // {
    //     cout << "Inside Copy Constructor" << endl;
    //     price = X.price;
    //     model = X.model;
    //     name = new char[strlen(X.name) + 1];
    //     strcpy(name, X.name);
    // }

    //shalow copy
    // Car(Car &X)
    // {
    //     cout << "Inside shallow Copy Constructor" << endl;
    //     price = X.price;
    //     model = X.model;
    //     name = X.name;
    // }

    // deep copy
    Car(Car &X)
    {
        cout << "Inside deep Copy Constructor" << endl;
        price = X.price;
        model = X.model;
        name = new char[strlen(X.name) + 1]; // deep copy // allocating new memory
        strcpy(name, X.name);
    }

    // copy assignment operator
    void operator=(Car &X)
    {
        cout << "Inside Copy Assignment Operator" << endl;
        price = X.price;
        model = X.model;
        name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
    }

    void setName(char *n)
    {
        if (name == NULL)
        {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        else
        {
            // delete old name array and allocate new one
        }
    }

    void start()
    {
        cout << "Starting the car " << name << endl;
    }

    void setPrice(int p)
    {
        if (p > 1000)
        {
            price = p;
        }
        else
        {
            price = 1000;
        }
    }

    int getPrice()
    {
        return price;
    }

    void print()
    {
        cout << name << endl;
        cout << model << endl;
        cout << price << endl;
        cout << endl;
    }

    // destructor
    ~Car()
    {
        cout << "Inside Destructor " << name << endl;
        // if (name != NULL)
        // {
        //     delete[] name;
        // }
    }
};

int main()
{

    // create an object
    Car c;

    // initialize data members
    c.model = 1001;
    c.name = "BMW";
    c.setPrice(500);

    // print data members
    cout << c.model << endl;
    cout << c.name << endl;
    cout << c.getPrice() << endl;

    // create another object
    Car d(100, 200, "Audi");
    d.print();

    // create third object
    Car e(d);
    e.name[0] = 'B';
    d.print();
    e.print();

    return 0;
}