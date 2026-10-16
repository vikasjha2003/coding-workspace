#include<iostream>
using namespace std;

class Human {
    string name;
    int age;

    public: 
    Human() {
        cout<<"Human Constructor"<<endl;
    }
    ~Human() {
        cout<<"Human Destructor"<<endl;
    }
};

class Employee : public Human {
    string company;

    public:
    Employee() {
        cout<<"Employee Constructor"<<endl;
    }
    ~Employee() {
        cout<<"Employee Destructor"<<endl;
    }    
};

class Manager : public Employee {
    string company;

    public:
    Manager() {
        cout<<"Manager Constructor"<<endl;
    }
    ~Manager() {
        cout<<"Manager Destructor"<<endl;
    }    
};

// first parent con then child con then first child des then parent des;

int main () {
    Manager Vikas;
}

// Hierarchial , Hybrid and Multipath studied but example not implemented.
// Multi path -> B inhertits from A , C inherits from A, D inherits from both B and C and gets A as well from both paths