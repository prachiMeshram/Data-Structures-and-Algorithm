#include<bits/stdc++.h>
using namespace std;

class A {

    // FUNCTION OVERLOADING
    public:
    void sayHello() {
        cout << "Hello bro" << endl;
    }

    int sayHello(char name) {
        cout << "Hello bro" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name << endl;
    }
};

class B {

    public:
    int a;
    int b;

    public:

    int add () {
        return a+b;
    }

    // OPERATOR OVERLOADING
    void operator+ (B &obj) {
        // int value1 = this->a;
        // int value2 = obj.a;

        // cout << "output: " << value2-value1 << endl; 

        cout << "love babbar" << endl;
    }

    void operator() () {

        cout << "bracket overloading" << this-> a << endl;
    }
};

class Animal {

    public:
    void speak( ) {
        cout << "speaking " <<endl;
    }
};

class Dog: public Animal {

    public:
    void speak( ) {
        cout << "barking " <<endl;
    }
};


int main () {

    Dog d;
    d.speak();

    // A obj;
    // obj.sayHello();

    // B obj1, obj2;

    // obj1.a = 4;
    // obj2.a = 7;

    // obj1 + obj2;

    // obj1();

    return 0;
}