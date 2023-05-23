#include<bits/stdc++.h>
using namespace std;


// syntax for initialisation list in constructor:
// constructor (argument-list) : initialization-section 
// {
//     assignment + other code;
// }

class Test {
    int a;
    int b;

    public:
    Test (int i, int j) : a(i), b(j) 
    // Test (int i, int j) : a(i), b(i+j) 
    // Test (int i, int j) : a(i), b(i*j) 
    // Test (int i, int j) : a(i), b(i*j) 
    // Test (int i, int j) : b(j), a(i+b) // RED FLAG -- THIS WILL CREATE PROB (coz a will initialize first)
    {
        cout << "constructor executed" << endl;
        cout << "value of a: " << a <<endl;
        cout << "value of b: " << b <<endl;
    }
    // below syntax is also correct
    // Test (int i, int j) : a(i)
    // {
    //     b = j;
    //     cout << "constructor executed" << endl;
    //     cout << "value of a: " << a <<endl;
    //     cout << "value of b: " << b <<endl;
    // }

};

int main() {
    Test t(4, 6);
    return 0;
}