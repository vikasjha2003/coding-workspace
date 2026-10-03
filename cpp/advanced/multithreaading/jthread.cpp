#include<iostream>
#include<thread>
#include<vector>

using namespace std;

int main () {

    auto lambda = [] () {
        cout<<"Hello from the lambda thread"<<endl;
        cout<<"My ID: "<<this_thread::get_id()<<endl;
    };

    vector<jthread> threads;

    for(int i = 0; i<10; i++) {
        threads.push_back(jthread(lambda));
    }

    // jthreads automatically join when their jthread objects are destroyed
    return 0;
}