// Interface -> .hpp or .h files
// Declaration of stuff, imported as headers in implementation.

// Implementation -> .cpp or .c
// where the work is done

// we will have to compile the cpp file and this main file as well to make it work.

#include<iostream>
#include "vikasmath.hpp"

using namespace std;

int main () {
    cout<<sum(5,6);
    return 0;
}