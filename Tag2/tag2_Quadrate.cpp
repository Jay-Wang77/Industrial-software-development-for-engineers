#include<iostream>
#include"tag2_Quadrate.h"
using namespace std;


Square::Square(int Kantenlaenge){
  this->Kantenlaenge = Kantenlaenge;
}

Square::Square(const Square& other){
  this->Kantenlaenge = other.Kantenlaenge;
}

int Square::getLaenge(){
    return Kantenlaenge;
}

int Square::getFlaeche(){
  return Kantenlaenge*Kantenlaenge;
}

int Square::getUmfang(){ 
  return Kantenlaenge*4;
}

void Square::printCharac(){
  cout<<"Laenge ist:"<<getLaenge()<<endl;
  cout<<"Flaeche ist:"<<getFlaeche()<<endl;
  cout<<"Umfang ist:"<<getUmfang()<<endl;
}

Square Square::operator+(const Square& other) const{
  return Square(this->Kantenlaenge+other.Kantenlaenge);
}
Square Square::operator-(const Square& other) const{
  return Square(this->Kantenlaenge-other.Kantenlaenge);
}
ostream& operator<<(std::ostream &os, Square &co) {
  return os << "Quadrat: Kantenlaenge = "<< co.getLaenge() << " , Flaeche = " << co.getFlaeche() <<", Umfang = " << co.getUmfang();
}


int main(){
  Square s1(10);
  cout<<s1<<endl;
  
  Square s2 = s1; 
  s2.printCharac();

  Square s3 = s1+s2;
  s3.printCharac();

  Square s4 = s1-s2;
  s4.printCharac();

  return 0;
}
