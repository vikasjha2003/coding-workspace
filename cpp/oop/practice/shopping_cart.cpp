#include<iostream>
#include<unordered_map>
using namespace std;

class Product {
    private:
    string name;
        int price;

    public:
        Product(string name, int price) {
            this->name = name;
            this->price = price;
        }

        int get_price() {
            return price;
        }

        string get_name() {
            return name;
        }
};

class ShoppingCart {
    private:
        unordered_map<Product*,int> cart;
        int total_items;
        int total_amount;

    public:
        ShoppingCart () {
            total_amount = 0;
            total_items = 0;
        }

        void add_product(Product* p1, int quantity) {
            if(quantity < 1) throw "Item quantity can't be less than one\n";
            cart[p1] += quantity;
            total_items += quantity;
            total_amount += p1->get_price() * quantity;
        }

        void reduce_quantity(Product* p1, int quantity) {
            if(quantity < 1) throw "Item quantity can't be less than one\n";
            if(quantity >= cart[p1]) {
                remove_product(p1);
                return;
            }
            cart[p1] -= quantity;
            total_items -= quantity;
            total_amount -= p1->get_price() * quantity;
        }

        void remove_product(Product* p1) {
            total_amount -= cart[p1] * p1->get_price();
            total_items -= cart[p1];
            cart.erase(p1);
        }

        int total_bill () {
            return total_amount;
        }
};

int main () {
    ShoppingCart cart1;

    Product* p1 = new Product("Lays",20);
    Product* p2 = new Product("Kurkure",10);

    try {
        cart1.add_product(p1,5);
        cart1.add_product(p2,6);

        cout<<cart1.total_bill()<<endl;

        cart1.reduce_quantity(p1,0);
    } catch (const char* e) {
        cout<<"Exception occured : "<<e;
    }

}