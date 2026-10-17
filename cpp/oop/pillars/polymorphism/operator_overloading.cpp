#include<iostream>
using namespace std;

class Complex {
    int real , img;
    public:
    Complex() {
        real = 0;
        img = 0;
    }
    Complex(int real , int img) {
        this->real = real;
        this->img = img;
    }

    Complex operator + (Complex &c1) {
        Complex ans;
        ans.real = this->real + c1.real;
        ans.img = this->img + c1.img;
        return ans;
    }

    void display() {
        cout<<real<<" + i"<<img<<endl;
    }
};

int main () {
    Complex num1 = Complex(5,6);
    Complex num2 = Complex(2,2);

    num1.display();
    num2.display();

    // If we don't overload the operators then below code will give error
    Complex num3 = num1 + num2;
    num3.display();
}