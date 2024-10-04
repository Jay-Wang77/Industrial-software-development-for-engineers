#include <iostream>

int get_length_dec(int num){
    int len = 0;
    while (num >= 1) {
        num /= 10;
        len += 1;
    }
    return len;
}

int main(){
    std::cout<<"Hier koennen Sie eine Dezimalzahl eingeben. Sie wird zur Maya-Zahl umgewandelt:\n";
    int dez_num =0;
    std::cin >> dez_num;  
    while(std::cin.fail())   // Gehe in Schleife solange Failbit gesetzt  
    {  
        std::cout << "Falscheingabe" << std::endl;  
        std::cin.clear();   // Setze Failbit zurück  
        std::cin.ignore(1000, '\n'); // Verwerfe bisherige Eingabe bis zu einem Zeilenumbruch  
        std::cin >> dez_num;  // Versuche Zuweisung erneut  
    } 
    int len = get_length_dec(dez_num);
    std::cout << "Die entsprechende Maya-Zahl ist gleich: "<< std::endl;
    int stelle = 0;
    int iter = dez_num;
    while(iter > 0){
            stelle = iter  % 20 ;
            iter = iter /20;
            std::cout<<stelle <<std::endl;
    }
    return 0;   
}