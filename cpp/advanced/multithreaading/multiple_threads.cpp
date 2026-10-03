#include<iostream>
#include<thread>
#include<vector>

using namespace std;

int main () {

    auto lambda = [] () {
        cout<<"Hello from the lambda thread"<<endl;
        cout<<"My ID: "<<this_thread::get_id()<<endl;
    };

    vector<thread> threads;
    // for(int i = 0; i<10; i++) {
    //     threads.push_back(thread(lambda));
    //     threads[i].join();
    // }

    // In the above code 10 threads are being launched but they are not being executed concurrently, the threads are joined right after pushing them to vector which results in them being fully executed and completed before next thread is pushed.

    for(int i = 0; i<10; i++) {
        threads.push_back(thread(lambda));
    }

    for(auto &t : threads) {
        t.join();
    }

    return 0;
}