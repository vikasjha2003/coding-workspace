#include<iostream>
#include<thread>

using namespace std;

void test () {
    cout<<"Hello from the thread"<<endl;
}

int main () {

    thread myThread(&test);
    

    cout<<"Hello from the main thread"<<endl;

    myThread.join();
    // Join with the main thread, which is same as saying "hey main thread wait untill myThread finishes execution before executing further"

    cout<<"Hello again from main thread"<<endl;

    return 0;
}