#include<iostream>
#include<vector>
using namespace std;

class Animal {
    public:
    // Virtual function
    virtual void speak () {
        cout<<"Speaking..."<<endl;
    }
};

// Abstract class , Can't create object of an abstract class, purely meant to be inherited.
class Human {
    public:
    // Pure virtual function, Purely meant to be inherited
    virtual void something () = 0;
};

class Dog : public Animal {
    public:
    void speak() {
        cout<<"Woof Woof!"<<endl;
    }
};

int main () {
    // Animal *husky;
    // husky = new Dog();

    // // Without virtual function, expected answer should be "Woof Woof!" but the actual answer is "Speaking..."
    // // this is because compiler decides at compile time which function to call
    // husky->speak();

    // // When using Virtual function compiler decides which function to call at runtime so output will be "Woof Woof!"

    // but why not directly make an object of dog class??

    vector<Animal*> animals;
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Dog());
    animals.push_back(new Animal());

    for(int i = 0; i<animals.size(); i++) {
        animals[i]->speak();
    }

    // without the virtual function we will have to check again and again what type of object we are handling and it will be difficult to store all of them together.
}