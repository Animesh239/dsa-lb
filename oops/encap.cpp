#include<iostream>
using namespace std ;

class Human{
    public:
        string name;
        int age;
        int weight;

    public:
        int getAge(){
            return this->age;
        }

        int getWeight(){
            return this->weight;
        }

        void setWeight(int w){
            this->weight = w;
        }
};

class Male : public Human {

    public:
        string color ;

    void sleep(){
        cout << "I am sleeping" << endl;
    }
};

int main(){

    Male m1;

    m1.setWeight(60);
    cout << m1.getWeight() << endl;
    m1.sleep();

    return 0;
}