#include<thread>
#include<iostream>
#include<future>

using namespace std;

int square(int x) {
    return x*x;
}

int main () {
    future<int> asyncFunction = async(&square,15); // square is executed by a different thread 

    for(int i = 0; i<10; i++) { // this is executed by the main thread
        cout<<i<<" ";
    }
    cout<<endl;

    // async helps us run different threads simultaneously

    // We are blocked at the get() method until our result has been calculated.
    int result = asyncFunction.get();
    cout<<result<<endl;

    return 0;
}

// When we use youtube we have the red bar which is the stuff already loaded and watched but there is a gray area which has been loading (buffering).
// this showcases how async can be helpful