#include <iostream>
#include <string>
#include <algorithm>


std::string Umkehr_Wort(std::string Wort_ein){
    char temp;
    int len = Wort_ein.size();
    if (len<4){
        return Wort_ein;
    }
    for (int i =1; i<((len/2)*2-1); i+=2){
        temp = Wort_ein[i];
        Wort_ein[i] = Wort_ein[i+1];
        Wort_ein[i+1] = temp;
    }
    return Wort_ein;
}

std::string Entfernung_Vokale(std::string Wort_ein){
    std::string Wort_aus;
    for (int i=0; i<Wort_ein.size(); i++){
        if (Wort_ein[i]!= 'a' && Wort_ein[i]!= 'e' && Wort_ein[i]!= 'i' && Wort_ein[i]!= 'o' && Wort_ein[i]!= 'u' && Wort_ein[i]!= 'A' && Wort_ein[i]!= 'E'&& Wort_ein[i]!= 'I' && Wort_ein[i]!= 'O'&&Wort_ein[i]!= 'U'){
            Wort_aus += Wort_ein[i];
        }
    }
    return Wort_aus;
}

int main(){
    std::string wort_ein;
    std::cout<< "Geben Sie ein Wort ein:" <<std::endl;
    std::cin>> wort_ein;
    std::string wort_umkehr;
    std::string wort_vokal;
    wort_umkehr = Umkehr_Wort(wort_ein);
    wort_vokal = Entfernung_Vokale(wort_ein);
    std::cout<<"Das Wort mit verkehrter Buchstabenreihenfolge lautet:\n"<<wort_umkehr<<std::endl;
    std::cout<<"----------------------------------------------------\n";
    std::cout<<"Das Wort ohne Vokale lautet:\n"<<wort_vokal<<std::endl;
    return 0; 
}


/*
int main(){
    std::string text_ein;
    std::cout<< "Geben Sie den Text ein:" <<std::endl;
    std::cin>> text_ein;
    int j = 0;
    std::string wort;
    std::string subtext;
    std::string text_umkehr;
    std::string text_vokal;

    while ( j < text_ein.size()){
        subtext = text_ein.substr(j);
        int i = subtext.find(' ');
        std::cout<<"i = "<<i<<std::endl;
        if (i == std::string::npos){
            wort = subtext;  // The rest of the string is the last word
            text_umkehr.append(Umkehr_Wort(wort));
            text_vokal.append(Entfernung_Vokale(wort));
            break;
        }
        if (text_ein[i-1] == ','|| '.'||':'||'!'||'?'){
            wort = text_ein.substr(0, i-2);
            text_umkehr.append(Umkehr_Wort(wort) + subtext[i-1] + subtext[i]);
            text_vokal.append(Entfernung_Vokale(wort) + subtext[i-1] + subtext[i]);
        }
        else{
            wort = text_ein.substr(0, i-1);
            text_umkehr.append(Umkehr_Wort(wort) + subtext[i]);
            text_vokal.append(Entfernung_Vokale(wort) + subtext[i]);
        }
        j += i+1;
    }
    std::cout<<"Der Text mit verkehrter Buchstabenreihenfolge lautet:\n"<<text_umkehr<<std::endl;
    std::cout<<"----------------------------------------------------\n";
    std::cout<<"Der Text ohne Vokale lautet:\n"<<text_vokal<<std::endl;
    return 0;
}
*/
