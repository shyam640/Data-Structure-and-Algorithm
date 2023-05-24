#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        int a;
        // default contructor
        A(){
            a = 10;
        }

        // parametrized contructor
        A(int val){
            a = val;
        }

        // copy contructor
        A(A &b){
            a = b.a;
        }

        // move contructor
        A(A && b){
            a = b.a;
        }

        void printVal(){
            cout<<"a = "<<a<<endl;
        }

};

int main(){
    A a1;   // default contructor called
    A a2(50);       // parametrized contructor called
    // a2.printVal();

    A a3(a2);       // copy contructor called
    // a3.printVal();

    A a4(A{20});    // move contructor called
    a4.printVal();

    return 0;
}