// Einbinden der benötigten Bibliotheken 
#include <cstdlib>  
#include <ctime> 
#include <iostream>  

int main() { 
    // Einmalige Initialisierung des random-seeds  
    srand(time(nullptr));
    int m = 0;
    int n = 100;
    int* Stack_ptr = new int[100000];
    int counter = 0;
    for (int i=0; i<100000; i++){
        int iNumber = rand() % n + m ;   // Zufallszahl zwischen [m, m+n[, kann öfters verendet werden  
        Stack_ptr[i] = iNumber;
    }

    for (int i = 0; i < 100000; i++) {
        if (Stack_ptr[i] % 13 == 0) {
            counter += 1;
        }
    }
    delete [] Stack_ptr;
    std::cout <<counter <<std::endl; 
    return 0;  
}