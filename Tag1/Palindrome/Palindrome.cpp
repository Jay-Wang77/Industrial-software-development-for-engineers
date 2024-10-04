#include <iostream>
#include <string>

int check_palindrome (std::string word){
    int len = word.size();
    std::string word_inv ;
    for (int i = len-1; i >= 0; i--){
        char buchstabe = word[i];
        if (buchstabe<'a' || buchstabe>'z'){
            std::cout << "Bitte nur Kleinbuchstabe eingeben\n";
            return -1;
        }
        word_inv.push_back(buchstabe);
    }
    if (word.compare(word_inv) == 0){
        std::cout<< word <<" ist ein Palindrome\n";
        return 1;
    }
    else{
        std::cout<< word <<" ist kein Palindrome\n";
        return 0;
    }
}

int main(){
    int test =-1;
    std::string wort;
    while (test == -1){
        
        std::cout<<"Geben Sie ein Wort aus Kleinbuchstaben:\n";
        std::cin >> wort;
        test = check_palindrome(wort);
    }
    return 0;
}