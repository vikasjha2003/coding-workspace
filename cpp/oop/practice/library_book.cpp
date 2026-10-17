#include<iostream>
using namespace std;

bool isValid(string &ISBN) {
    if(ISBN.length() != 13) return false;

    for(char c : ISBN) {
        if(c < '0' || c > '9') return false;
    }

    return true;
}

// For simplicity assume there is only one copy of each book in the library

class Book {
    private:
        string title;
        string author;
        string ISBN;
        bool available;
    
    public:
        Book(string title, string author, string ISBN) {
            if(!isValid(ISBN)) throw "ISBN is invalid for the given book!";
            this->title = title;
            this->author = author;
            this->ISBN = ISBN;
            this->available = true;
        }

        void getBookDetails() {
            cout<<title<<" by "<<author<<endl;
        }

        void issueBook() {
            if(!available) throw "Book is not available!";
            available = !available;
            cout<<title<<" issued successfully!\n";
        }

        void depositBook() {
            if(available) throw "Book has not been issued!";
            available = !available;
            cout<<title<<" deposited successfully!\n";
        }
};

int main () {
    try {
        Book book1 = Book("One Piece","Eichiro Oda","1234567891234");
        book1.getBookDetails();
        book1.issueBook();
        book1.depositBook();        
    } 
    catch (const char* e) {
        cout<<"Error : "<<e<<endl;
    }
}