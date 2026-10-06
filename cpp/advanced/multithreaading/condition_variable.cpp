#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<chrono>
#include<condition_variable>

using namespace std;

// When one threaad has access to a lock than if other threads will keep constantly checking if they have access to the lock or not then it will take a lot of computation ower which can be used elsewhere, so Condition variable solves this problem.

mutex gLock;
condition_variable gCondition;

int main () {
    int result = 0;
    bool notified = false;

    // reporting thread
    thread reporter ([&]() {
        unique_lock<mutex> lock(gLock);
        if(!notified) {
            gCondition.wait(lock);
        }
        cout<< "Reporter result is: "<< result <<endl;
    });
    // working thread
    thread worker ([&]() {
        unique_lock<mutex> lock(gLock);
        // do our work
        result = 50 + 65 + 11;
        // Our work is done
        notified = true;
        this_thread::sleep_for(chrono::seconds(5));
        // wake up a thread that is waiting
        gCondition.notify_one();
    });
    worker.join();
    reporter.join();
    return 0;
}