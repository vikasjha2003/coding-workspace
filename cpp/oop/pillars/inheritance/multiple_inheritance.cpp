#include<iostream>
#include<optional>
using namespace std;

class Throwable{
    protected:
    int quantity;
    optional<int> time;

    public:
    int get_quantity() {
        return quantity;
    }
};

class Melee{
    protected:
    bool have;
};

class Dagger: public Throwable, public Melee{
    int range;
    public:
    Dagger() {
        time = nullopt;
        have = true;
        quantity = 1;
        range = 10;
    }    
};

int main() {
    Dagger kukri;
    cout<<kukri.get_quantity();
}