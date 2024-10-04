#include <iostream>
#include <math.h>


bool Quad_Funk(double a, double b, double c, double* x1_ptr, double* x2_ptr){
   
    double delta = b*b-4*a*c;
    if (delta<0){
        return false;
    }
    else{
        *x1_ptr = (-b + sqrt(delta))/2/a;
        *x2_ptr = (-b - sqrt(delta))/2/a;
        return true;
    }
}

int main(){
    double a, b, c, x1, x2;
    bool mode = true;
    while (mode ==true){
        std::cout<<"a = \n";
        std::cin>> a;
        std::cout<<"b = \n";
        std::cin>> b;
        std::cout<<"c = \n";
        std::cin>> c;
        if (Quad_Funk(a, b, c, &x1, &x2) == false){
            std::cout<<"keine Loseung\n";            
        }else{
            std::cout<<"x1 = "<< x1 <<std::endl;
            std::cout<<"x2 = "<< x2 <<std::endl;
        }
        std::cout<<"Wollen Sie weiter rechnen(1) oder das Programm beenden(0)?"<<std::endl;
        std::cin>>mode;
    }
    return 0;
}
  

