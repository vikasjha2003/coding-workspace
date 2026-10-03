#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<chrono>

using namespace std;

// Mutex -> Mutual Exclusion (Binary Semaphore 0 or 1)
// Used to lock section of code so that only one thread can access that section at any given time

mutex gLock;

int main () {

    int shared_val = 0;
    auto lambda = [&] () {
        
        // Mutex Lock
        gLock.lock();
            // Critical section
            shared_val = shared_val + 1;
            shared_val = shared_val + 1;
            shared_val = shared_val + 1;
            shared_val = shared_val + 1;
            shared_val = shared_val + 1;
        gLock.unlock();
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