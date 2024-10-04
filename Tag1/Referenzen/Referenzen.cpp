#include <iostream>

 void swap(int &n1, int &n2){
        int temp =n2;
        n2 = n1;
        n1 = temp;
    }

int main(){
   int a =5;
   int b =6;
   swap(a, b);
   std::cout<<"a = "<<a<<std::endl;
   std::cout<<"b = "<<b<<std::endl;
   return 0;
}