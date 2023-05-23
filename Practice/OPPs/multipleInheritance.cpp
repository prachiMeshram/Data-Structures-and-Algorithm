#include<bits/stdc++.h>
using namespace std;

class Animal {

    public:
    int age;
    int weight;

    public:
    void bark() {
        cout << "barking" << endl;
    }
};

class Human  {
    public:
    string color;

    public:
    void speak() {
        cout << "speaking" << endl;
    }
};

// multiple inheritance 
class Hybrid: public Animal, public Human {

};

int main () {

    Hybrid d;
    d.speak();
    d.bark();

    return 0;
}