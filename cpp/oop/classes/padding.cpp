#include<iostream>
// c p p p a a a a b p p p
class A {
    char c;
    int a;
    char b;
};

// a a a a c b p p
class B {
    int a;
    char c;
    char b;

    public: 
    B () {
        // default constructor
    }
    inline B(int i , char ch, char cha) : a(i) , c(ch), b(cha) {} // An inline constructor
};

int main () {
    // This object exists in static memory, if we declare using dynamic allocation then will be in heap memory.
    A obj1;
    B obj2;
    std::cout<<sizeof(obj1)<<std::endl; // should be 12
    std::cout<<sizeof(obj2)<<std::endl; // should be 8

    // follow the general approach of writing data with largest size first and then move to smaller data in class. 

    A *obj = new A;
}