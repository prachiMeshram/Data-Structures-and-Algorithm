// https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381816?leftPanelTab=0

#include <bits/stdc++.h> 
#include<iostream>

#include<algorithm>

using namespace std;

class Fraction {

    // Complete the class
    
    public:
    int num, den;

    public:
    Fraction (int n, int d) {
        num = n;
        den = d;
    }

    void add (Fraction &F) {
        // (a/b) + (c/d) = (ad+cb)/(bd);

        if (den == F.den) {
            num = num+F.num;
        }
        else {
            int ad = (num*F.den);
            int cb = (den*F.num);
            int bd = (den*F.den);

            num = ad+cb;
            den = bd;
        }  
    }

    void multiply (Fraction &F) {
        // (a/b) * (c/d) = (ac)/(bd);

        num = this->num*F.num;
        den = this->den*F.den;
    }

    int simplify (int n, int d) {
        // int gcd = __gcd(F.num, F.den);

        // F.num = F.num/gcd;
        // F.den = F.den/gcd;
        return __gcd(n, d);
    }

    void print () {
        int sim = simplify(num, den);
        cout << num/sim << "/" << den/sim << endl;
    }
};

int main() {

    //Write your code here


    int numerator, denominator;
    cin >> numerator >> denominator;

    Fraction *f1 = new Fraction(numerator, denominator);

    int totalQueries;
    cin >> totalQueries ;

    //  query 
    // type 1 == addition
    // type 2 == multiplication

    for (int i = 0; i < totalQueries; i++) {
        int operation; 
        int N;
        int D;
        cin >> operation >> N >> D;

        Fraction *f2 = new Fraction (N, D);

        if (operation == 1) {
            f1->add(*f2);
            f1->print();
        }
        else if (operation == 2) {
            f1->multiply(*f2);
            f1->print();
        }
    }


    return 0;
}