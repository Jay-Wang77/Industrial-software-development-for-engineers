#ifndef FLASCHEN_H 
#define FLASCHEN_H

#include<iostream>
#include<string>

using namespace std;

class Flaschen{
  private:
    double dVolumen;
    string sMaterial;
  public:
    Flaschen(double dVoulumen, string sMaterial);
    double getVolumen();
    string getMaterial();

    void setVolumen(double dVolumen);

    void setMaterial(string sMaterial);

    void printFlasche();

    bool adoptFlasch(Flaschen &flasche);
};

#endif