// main.cpp
#include "Polymorphie.h"

int main() {
    A a = A(); 
    a.f();  

    B b = B(); 
    b.g(); 

    C c = C(); 
    c.g(); 

    //B b0 = A(); // 2. child class can not point to parent
    //b0.g(); 

    A a1 = B(); 
    a1.f(); 

    A a2 = b; 
    a2.f(); 
}