#include<bits/stdc++.h>

using namespace std;

class FooBar {
private:
    int n;
    bool notified = false;
    mutex gLock;
    condition_variable gCondition;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(gLock);
        for (int i = 0; i < n; i++) {
            gCondition.wait(lock,[&](){
                return !notified;
            });
        	printFoo();
            notified = true;
            gCondition.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(gLock);
        for (int i = 0; i < n; i++) {
            gCondition.wait(lock,[&](){
                return notified;
            });        	
        	printBar();
            notified = false;
            gCondition.notify_one();
        }
    }
};