#include<iostream>
using namespace std;

class Human {
    string name;
    int age;

    public: 
    Human() {
        cout<<"Parent Constructor"<<endl;
    }
    ~Human() {
        cout<<"Parent Destructor"<<endl;
    }
};

class Student : public Human {
    string grade;

    public:
    Student() {
        cout<<"Student Constructor"<<endl;
    }
    ~Student() {
        cout<<"Student Destructor"<<endl;
    }    
};

// first parent con then child con then first child des then parent des;

int main () {
    Student Vikas;
}