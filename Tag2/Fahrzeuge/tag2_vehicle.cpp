#include <iostream>
#include <string>
#include "tag2_vehicle.h"
using namespace std;


Vehicle::Vehicle(string farbe, double Preis, int Baujahr):m_farbe(farbe), m_Preis(Preis), m_Baujahr(Baujahr){
  ID++;
  globalID = ID;
}

bool Vehicle::isOldtimer(int Baujahr){
  return Baujahr<1980;
}

int Vehicle::getBaujahr(){
  return m_Baujahr;
}

void Vehicle::getID(){
  cout<< globalID<<endl;
}

int Vehicle::ID = 0;
int main(){
  Vehicle v1("rot", 1000, 1990);
  Vehicle v2("blau", 2000, 1970);
  Vehicle v3("gruen", 3000, 1980);
  cout<<Vehicle::isOldtimer(v1.getBaujahr())<<endl;
  cout<<Vehicle::isOldtimer(v2.getBaujahr())<<endl;
  cout<<Vehicle::isOldtimer(v3.getBaujahr())<<endl;
  v1.getID();
  v2.getID();
  v3.getID();
  //cout<<v1.getID()<<endl;
  //cout<<v1.getID()<<endl;   
  //cout<<v1.getID()<<endl;
  return 0;
}
