#include<iostream>
using namespace std;

// Encapsulation is used to control the access of members in a class using access modifier
// This helps in preventing data from unwanted entries or modification
// Think of the situation where someone gets infinite health in a video game

class Customer {
    private: // Inaccessible outside the class
    string name;
    int account_number, balance;
    static int total_customer;

    public: // Accessible from outside the class
    Customer(string name, int account_number,int balance) {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance; 
        total_customer++;
    }
    static int getTotal() {
        return total_customer;
    }
};

// protected -> Unaccessible from outside the class but can be inherited by other class

int Customer::total_customer = 0;

int main () {

    cout<<Customer::getTotal()<<endl;

    Customer C1("Vikas",1,1000);

    cout<<C1.getTotal()<<endl;

    cout<<Customer::getTotal()<<endl;
}