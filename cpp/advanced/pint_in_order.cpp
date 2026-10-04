#include<bits/stdc++.h>
using namespace std;

class Foo {
public:
    int val = 1;
    mutex gLock;
    condition_variable gCondition;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(gLock);
        printFirst();
        val = 2;
        gCondition.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(gLock);
        gCondition.wait(lock,[&](){
            return val == 2;
        });
        printSecond();
        val = 3;
        gCondition.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(gLock);
        gCondition.wait(lock,[&](){
            return val == 3;
        });
        printThird();
    }
};