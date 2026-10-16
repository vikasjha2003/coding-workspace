#include<iostream>
using namespace std;

// Static variables are attributes of class that is they belong to class
// Static variables can be accessed directly using sttic member functions 
class Customer {
    private:
    string name;
    int account_number, balance;
    static int total_customer;

    public:
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

// :: -> scope resolution variables
int Customer::total_customer = 0;

int main () {

    cout<<Customer::getTotal()<<endl;

    Customer C1("Vikas",1,1000);

    cout<<C1.getTotal()<<endl;

    cout<<Customer::getTotal()<<endl;
}