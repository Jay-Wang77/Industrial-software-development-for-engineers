#include<iostream>
#include "tag2_Flaschen.h"
using namespace std;

Flaschen::Flaschen(double dVolumen, string sMaterial){
  this->dVolumen = dVolumen;
  this->sMaterial = sMaterial;
}
double Flaschen::getVolumen(){
  return dVolumen;
}
string Flaschen::getMaterial(){
  return sMaterial;
}

void Flaschen::setVolumen(double dVolumen){
  this->dVolumen = dVolumen;
}

void Flaschen::setMaterial(string sMaterial){
  this->sMaterial = sMaterial;
}

void Flaschen::printFlasche(){
  cout<<"Volumen: "<<getVolumen()<<endl;
  cout<<"Material: "<<getMaterial()<<endl;
}

bool Flaschen::adoptFlasch(Flaschen &flasche){
  if(this->dVolumen == flasche.getVolumen() && this->sMaterial == flasche.getMaterial()){
    return true;
  }
  return false;
  }

int main(){
  Flaschen flaschen1(2.0, "Glas");
  Flaschen flaschen2(3.0, "Gold");
  
  flaschen1.printFlasche();
  flaschen2.printFlasche();
  if(flaschen1.adoptFlasch(flaschen2)){
    cout<<"Adopted"<<endl;
  }
  else{
    cout<<"Not Adopted"<<endl;
  }

  flaschen1.setVolumen(3.0);
  flaschen1.setMaterial("Gold");

  flaschen1.printFlasche();
  flaschen2.printFlasche();
  if(flaschen1.adoptFlasch(flaschen2)){
    cout<<"Adopted"<<endl;
  }
  else{
    cout<<"Not Adopted"<<endl;
  }

  return 0;
}