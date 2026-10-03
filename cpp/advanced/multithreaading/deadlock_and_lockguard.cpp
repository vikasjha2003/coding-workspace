#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

using namespace std;

mutex gLock;

int main () {

    int shared_val = 0;
    auto lambda = [&] () {
        lock_guard<mutex> lockGuard(gLock);  // Automatically locks when in scope and unlocks when out of scope
        
        // Mutex Lock
        // gLock.lock();
            // Critical section
            shared_val = shared_val + 1;
        // gLock.unlock();  // Causes Deaadlock if commented out

        // All the threads are blocked and never able to make progress
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