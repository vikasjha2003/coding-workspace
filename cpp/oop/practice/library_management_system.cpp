#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Book {
    private:
        string name;
        string author;
    
    public:
        Book(string name, string author) {
            if(name.length() == 0) throw "Book must have a valid name";
            if(author.length() == 0) throw "Book author must have a valid name";
            this->name = name;
            this->author = author;
        }

        string get_name() {
            return name;
        }

        string get_author() {
            return author;
        }
};

class Member {
    private:
        string name;
        int member_id;
        static int total_members;

    public:
        Member(string name) {
            if(name.length() == 0) throw "Member must have a valid name";
            this->name = name;
            member_id = ++total_members;
        }

        string get_name() {
            return name;
        }

        int get_id() {
            return member_id;
        }
};

class Library {
    private:
        unordered_map<Book*,int> books;
        unordered_map<Member*,int> members;
        int limit;

    public:
        Library(int limit) {
            this->limit = limit;
        }

        void add_book(Book* book, int quantity) {
            if(quantity < 1) throw "Quantity of books can't be less than 1";
            books[book] += quantity;
        }

        void add_member(Member* member) {
            if(members.find(member) != members.end()) throw "Already a member of the library";
            members[member] = 0;
        }

        int get_book_cnt(Book* book) {
            if(books.find(book) == books.end()) throw "Book not found in the Library";
            return books[book];
        }

        void borrow_book(Book* book, Member* member) {
            if(books.find(book) == books.end()) throw "Book not found in the Library";
            if(members.find(member) == members.end()) throw "Not a member of the library";
            if(members[member] == limit) throw "Member already has maximum number of books issued";
            if(books[book] == 0) throw "Book is unavailable at the moment, try laster";
            books[book]--;
            members[member]++;

            cout<<"Book issued successfully!\n";
        }

        void return_book(Book* book, Member* member) { // has a bug, not keeping track of whether the book being is returned was issued to current member or not
            if(books.find(book) == books.end()) throw "Book not found in the Library";
            if(members.find(member) == members.end()) throw "Not a member of the library";
            if(members[member] == 0) throw "No book issued to member";
            books[book]++;
            members[member]--;

            cout<<"Book returned successfully!\n";
        }

};

int Member::total_members = 0;

int main () {
    // Main function implement using try and catch later, too lazy to do now
}