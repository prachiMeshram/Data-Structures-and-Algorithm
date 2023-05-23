#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
    
    private:

    int real, img;

    public:
    
    ComplexNumbers (int r, int i) {
        this->real = r;
        this->img = i;
    }

    void plus(ComplexNumbers &b) {

        real = this-> real + b.real;
        img = this-> img + b.img;
    }

    void multiply(ComplexNumbers &b) {
        // (a+ib)(c+id) = (ac-bd) + i(ad+bc)

        int ac = this->real*b.real;
        int bd = this->img*b.img;

        int ad = this->real*b.img;
        int bc = this->img*b.real;

        real = ac-bd;
        img = ad+bc;

        // real = ((this->real)*(b.real)) - ((this->img)*(b.img));
        // img = ((this->real)*(b.img)) + ((this->img)*(b.real));
    }

    void print () {
        cout << real << " + i" <<img;
    }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}