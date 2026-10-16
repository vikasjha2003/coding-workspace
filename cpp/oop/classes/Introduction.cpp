// Class is a user defined data type
#include<iostream>
#include "student.hpp"
using namespace std;

// in heap memory destructor is not called automatically, we need to use delete keyword

// in stack memory destructor is called automatically when out of scope, the object created first will be deleted last.

int main () {
    // An object, Has state and behaviour
    student st1 = student("Vikas");
    cout<<st1.getName()<<endl;

    // try to make class but this type use interface and implementation to do this.
}