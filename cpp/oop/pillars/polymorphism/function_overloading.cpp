#include<iostream>
using namespace std;
int sum (int a , int b) {
    return a + b;
}
int sum (int a , int b , int c) {
    return a+b+c;
}

// Which function to call is decided at compile time by the compiler.
// Static polymorphism

int main () {
    cout<<sum(5,7,9)<<endl;
    cout<<sum(3,2)<<endl;
}