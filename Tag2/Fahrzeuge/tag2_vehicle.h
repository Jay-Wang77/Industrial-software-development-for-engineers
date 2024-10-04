#ifndef VEHICLE_H 
#define VEHICLE_H

#include<iostream>
#include<string>
using namespace std;

class Vehicle {
public:
  enum farbe {rot, gruen, blau, weiss, schwarz};
  Vehicle(string farbe, double Preis, int Baujahr);
  static bool isOldtimer(int Baujahr);
  int getBaujahr();
  void getID();
  
  static int ID;
  int globalID;
private:
  string m_farbe;
  double m_Preis;
  int m_Baujahr;
};

#endif