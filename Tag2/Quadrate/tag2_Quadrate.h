#ifndef SQUARE_H
#define SQUARE_H
#include<iostream>

using namespace std;

class Square{
public:
  Square(int Kantenlaenge);
  Square(const Square& other);
  Square& operator=(const Square& other);
  int getFlaeche();
  int getUmfang();
  int getLaenge();
  void printCharac();

  Square operator+(const Square& other) const;
  Square operator-(const Square& other) const;

private:
  int Kantenlaenge;
  int Flaeche;
  int Umfang;
};

#endif