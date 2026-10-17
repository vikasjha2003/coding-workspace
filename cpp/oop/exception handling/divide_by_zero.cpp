#include<iostream>
using namespace std;
int main () {
    int a , b;
    cin>>a>>b;

    try {
        if(b == 0) 
        throw "Divide by zero is Not Defined";

        int result = a / b;
        cout<<result;
    } catch (const char *e){
        cout<<"Exception Occurred : "<<e<<endl;
    }
}