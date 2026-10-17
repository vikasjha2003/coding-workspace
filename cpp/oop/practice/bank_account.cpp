#include<iostream>
using namespace std;

class BankAccount {
    private:
        string acc_holder;
        int acc_number;
        int balance;
        static int number;

    public:
        // Constructor
        BankAccount(string name, int balance) {
            this->acc_holder = name;
            this->acc_number = ++number;
            this->balance = balance;
        }

        void deposit(int amount) {
            if(amount < 1) throw "Zero or Negative deposit ammount is not supported, Please enter a valid amount";
            balance += amount;
        }

        void withdraw(int amount) {
            if(amount < 1) throw "Zero or Negative  withdrawal amount is not supported, Please enter a valid amount";
            if(amount > balance) throw "Insufficient Balance, Please check your balance";
            balance -= amount;
        }

        void display_balance() {
            cout<<"Account Balance: "<<balance<<endl;
        }

        static void total_accounts() {
            cout<<number<<endl;
        }
};

int BankAccount::number = 0;

int main () {
    BankAccount::total_accounts();

    BankAccount *acc1 = new BankAccount("Vikas",1000);
    acc1->display_balance();
    
    try {
        acc1->deposit(500);
        acc1->withdraw(50);
    } catch (const char* e) {
        cout<<"Exception Occured: "<<e<<endl;
    }
    acc1->display_balance();
    acc1->total_accounts();
    
}