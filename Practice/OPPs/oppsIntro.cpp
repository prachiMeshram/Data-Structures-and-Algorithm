#include<bits/stdc++.h>
// #include "hero.cpp"
using namespace std;

class Hero {
    // properties

    // char name[100];
    private:
    int health;
     
    public:
    char* name;
    char level;
    static int timeToComplete;


    // once we write our own constructor, the inbuilt constructor will be removed automatically 
    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    // parameterised constructor 
    Hero (int health) {
        cout << "this -> " << this << endl;
        this->health = health;
    }

    Hero (int health, char level) {
        this->health = health;
        this->level = level;
    }
    // copy constructor
    // why are we using & (think)? 
    Hero(Hero& temp) {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }


    void print() {
        cout << endl;
        cout << "name: " << this->name << endl;
        cout << "health: " << this->health << endl;
        cout << "level: " << this->level << endl;
    }

    int getHealth() {
        return health;
    }
    
    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(int lvl) {
        level = lvl;
    }

    void setName(char name[]) {
        strcpy(this-> name, name);
    }

    static int random() {
        return timeToComplete;
        // cout << health << endl;
    }

    // DESTRUCTOR
    ~Hero() {
        cout << "destructor called" << endl;
    }
};

int Hero::timeToComplete = 5;

int main () {


    cout << Hero::random() << endl;


    // cout << Hero::timeToComplete<< endl;

    // Hero a;
    // cout << a.timeToComplete<< endl;

    // Hero b;
    // b.timeToComplete = 10;
    // cout << a.timeToComplete<< endl;
    // cout << b.timeToComplete<< endl;







    

    // Hero hero1;

    // hero1.setHealth(12);
    // hero1.setLevel('m');
    // char name[9] = "Babbar";
    // hero1.setName(name);

    // // hero1.print();

    // // use default copy constructor by commenting your own cpy constructor
    // Hero hero2(hero1);
    // // hero2.print();

    // hero1.name[0] = 'G';

    // hero1.print();
    // hero2.print();
    // // Hero hero2 = hero1;

    // hero1 = hero2;

    // hero1.print();
    // hero2.print();

    // statically called (destructor called automatically)
    // Hero A;

    // // dyanamic call (need to call destructor manually)
    // Hero *B = new Hero();
    // delete B; // manual call


    // Hero S(70, 'C');
    // S.print();

    // // copy constructor 
    // Hero R(suresh); // R.health = suresh.health; R.level = suresh.level; 
    // R.print();


    // Object created statically
    // cout << "hiee" << endl;
    // Hero ramesh(10); 
    // ramesh.print();
    // cout << "address of ramesh: " << &ramesh << endl;
    // cout << "hieello" << endl;
    // ramesh.getHealth();
    
    // // DYNAMICALLY 
    // Hero *h1 = new Hero;
    // h1->print();
    // Hero *h = new Hero(11);
    // h->print();

    // Hero temp(22, 'b');
    // temp.print();


    // Hero a; // STATIC ALLOCATION
    // a.setHealth(89);
    // a.setLevel('A');
    // cout << "level is: " << a.level << endl;
    // cout << "health is: " << a.getHealth()<< endl;

    // Hero *b = new Hero; // DYNAMIC ALLOCATION
    // b->setHealth(9);
    // b->setLevel('b');
    // cout << "level is: " << (*b).level << endl;
    // cout << "health is: " << (*b).getHealth()<< endl;

    // cout << "level is: " << b->level << endl;
    // cout << "health is: " << b->getHealth()<< endl;

    // creating object;
    // Hero ramesh;
    // cout << "health of ramesh is: " << ramesh.getHealth() << endl;

    // // Use Setter 
    // ramesh.setHealth(80);
    // // ramesh.health = 70;
    // ramesh.level = 'A';

    // cout << "health is: " << ramesh.getHealth() << endl;
    // cout << "level is: " << ramesh.level << endl;

    return 0;
}

