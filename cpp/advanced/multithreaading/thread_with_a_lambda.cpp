#include<iostream>
#include<thread>

using namespace std;

int main () {

    auto lambda = [] () {
        cout<<"Hello from the lambda thread"<<endl;
    };

    thread myThread(lambda);
    

    cout<<"Hello from the main thread"<<endl;

    myThread.join();

    cout<<"Hello again from main thread"<<endl;

    return 0;
}