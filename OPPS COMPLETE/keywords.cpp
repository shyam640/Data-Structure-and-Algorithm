#include<bits/stdc++.h>
using namespace std;

/*      static      */

// static -> whenever we define variable, function and class as static then it remains for the lifetime of program execution. 

class Static{
    public:
        void test(){
            static int a = 0;
            a++;
            cout<<a<<endl;
        }
        
};


/*      Virtual     */

// virtual ->  the virtual keyword in C++ is important for creating polymorphic behavior in classes. By declaring a function as virtual, derived classes can override it with their own implementations, allowing objects of different classes to be treated as if they were objects of the same class.

class Virtual{
    public:
        virtual void show(){
            cout<<"Base class show function !"<<endl;
        }
};

class d1 : public Virtual{
    public:
        void show(){
            cout<<"1st derived class show function !"<<endl;
        }
};

class d2 : public Virtual{
    public:
        void show(){
            cout<<"2nd derived class show function !"<<endl;
        }
};

class d3 : public d2{
    public:
        void show(){
            cout<<"4th derived class show function !"<<endl;
        }
};


// virtual class -> when B, C inherit from A and D inherit from B and C, then A compiler get confused when we call d to call show function because it gets B's A and C's A;

class A{
    public:
        virtual void show() = 0;
};

class B : public A{
    public:
        void show(){
            cout<<"B's show function"<<endl;
        }
};

class C : public A{
    public:
        void show(){
            cout<<"C's show function"<<endl;
        }
};


class D : public B, public C{
    public:
        void show(){
            cout<<"D's show function"<<endl;
        }
};

int main(){
    // static
    // Static a1;
    // a1.test();
    // a1.test();


    // virtual
    // Virtual* v;
    // d2 d;
    // v = &d;
    // v->show();

    
    // virtual class
    D d;
    d.show();

    

    return 0;
}