#include<iostream>
#include<thread>
#include<vector>
#include<atomic>

using namespace std;

int main () {

    atomic<int> shared_val = 0; // operators are overloaded so that whenever read is performed on the variable the variable is locked and other threads can't access the variable before write is done, it all happens on its own internally
    auto lambda = [&] () {
        shared_val++;    
    };
    
    vector<thread> threads;

    for(int i = 0; i<100; i++) {
        threads.push_back(thread(lambda));
    }

    for(int i = 0; i<100; i++) {
        threads[i].join();
    }

    cout<<shared_val<<endl;

    return 0;
}