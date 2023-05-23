// https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381817?leftPanelTab=0

#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class Person {

    // Complete the class
    private:

    string name;
    int age;

    public:
    
    void setValue(string n, int a) {
        name = n;
        age = a;
    }

    void getValue () {
        // cout << "The name of the person is " << name << " and the age is " << age <<".";
        cout << "The name of the person is " << name << " and the age is "<< age <<".";
    }

};

int main() {

    //Write your code here
    Person p;
    string Name;
    cin >> Name;

    int Age;
    cin >> Age;
    
    p.setValue(Name, Age);
    p.getValue();
    
    return 0;
}