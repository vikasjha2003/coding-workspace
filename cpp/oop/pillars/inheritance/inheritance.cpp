#include<iostream>
using namespace std;

// Inheritance is the capability of a class to inherit functionalities and properties from another class

class Human {
    public:
    string name;
    int age , weight;
};

class Student : public Human {
    int roll_number, fees;
};

int main () {
    Student vikas;
    vikas.age = 100;
    cout<<vikas.age;
}