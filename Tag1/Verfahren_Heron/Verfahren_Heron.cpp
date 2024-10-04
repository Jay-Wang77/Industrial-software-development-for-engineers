#include <iostream>

double heron_ite(int a){
    double x = a;
    for (int i = 0; i<10; i++){
        x = (x + a / x)*0.5;
    }
    return x;
}

int main(){
    int num =0;
    std::cout<<"Geben Sie eine ganze Zahl ein:\n";
    std::cin >> num;  
    while(std::cin.fail())   // Gehe in Schleife solange Failbit gesetzt  
    {  
        std::cout << "Falscheingabe: Bitte Ganzenzahl eingeben!" << std::endl;  
        std::cin.clear();   // Setze Failbit zurück  
        std::cin.ignore(1000, '\n'); // Verwerfe bisherige Eingabe bis zu einem Zeilenumbruch  
        std::cin >> num;  // Versuche Zuweisung erneut
    } 
    double wurzel = heron_ite(num);
    std::cout<<"Die Quardratwurzel von "<< num << " ist "<< wurzel <<std::endl;
    return 0;
}
