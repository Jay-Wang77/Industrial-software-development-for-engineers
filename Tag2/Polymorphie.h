#include <iostream>

class A {
public:
    virtual void g() {
        std::cout << "A.g\n";
        f();
    }
    
    virtual void f() {
        std::cout << "A.f\n";
        h();
    }
    
    virtual void h() { //1. virtual function
        std::cout << "A.h\n";
        i();
    }
    
    virtual void i() {
        std::cout << "A.i\n";
    }
};

class B : public A {
public:
    void g() override {
        std::cout << "B.g\n";
        f();
    }
    
    void f() override {
        std::cout << "B.f\n";
        A::f();
        h();
    }
};

class C : public A {
public:
    void g() override {
        std::cout << "C.g\n";
        f();
    }
    
    void h() override {
        std::cout << "C.h\n";
        i();
    }
    
    void i() override {
        std::cout << "C.i\n";
    }
};
