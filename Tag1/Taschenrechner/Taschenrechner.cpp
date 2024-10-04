#include <iostream>


int main(){  
    std::cout << "---------------------------\n";
    std::cout << "Der Taschenrechner liefert diese vier Operationen: \n";
    std::cout << "Addition (+)\n";
    std::cout << "Subtraktion (-)\n";
    std::cout << "Multiplikation (*)\n";
    std::cout << "Division (/)\n";

    beginning:
    char oper ;
    while (std::cin>>oper) {
        std::cout << "Bitte geben Sie Ihre Operation ein:";
        if (oper == '+' ||  oper == '-' ||  oper == '*' ||  oper == '/' ){
            break;
        } 
        std::cout << "Unguenstige Eingabe!\n";
    }

    a_b:
    double a =0.0;
    std::cout<< "Geben Sie die erste Zahl a ein: ";
    std::cin >> a;  
    while(std::cin.fail())   // Gehe in Schleife solange Failbit gesetzt  
    {  
        std::cout << "Falscheingabe" << std::endl;  
        std::cin.clear();   // Setze Failbit zurück  
        std::cin.ignore(1000, '\n'); // Verwerfe bisherige Eingabe bis zu einem Zeilenumbruch  
        std::cin >> a;  // Versuche Zuweisung erneut  
    } 
    double b =0.0;
    std::cout<< "Geben Sie die zweite Zahl b ein: ";
    std::cin >> b;  
    while(std::cin.fail())   // Gehe in Schleife solange Failbit gesetzt  
    {  
        std::cout << "Falscheingabe" << std::endl;  
        std::cin.clear();   // Setze Failbit zurück  
        std::cin.ignore(1000, '\n'); // Verwerfe bisherige Eingabe bis zu einem Zeilenumbruch  
        std::cin >> b;  // Versuche Zuweisung erneut  
    } 

    double res = 0.0;
    switch (oper){
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if (b == 0.0){
                std::cout<< "Divisior darf nicht Null sein!\n";
                std::cout<< "Bitte geben Sie erneut a und b!\n";
                goto a_b;
            }
            res = a / b;            
            break;
        default:
            std::cout<<"Rechnung geht nicht! Der Taschenrechner wird neu gestartet!\n";
            goto beginning;
    }

    std::cout << "Ergbnis = " << res << std::endl;
    return 0;
}

