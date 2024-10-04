#ifndef MANEUVER_H_
#define MANEUVER_H_

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

struct Coord {
    double dX;
    double dY;
    double dV;

    Coord(double x, double y, double v) : dX(x), dY(y), dV(v) {}
};

class Maneuver {
private:
    list<Coord> CoordList;
    list<Coord>::iterator iter;
    bool bIsRunning;
    double adWishSpeed[2];
    double dMaxSpeed;
    double dPosDifference;

public:
    Maneuver() : bIsRunning(false), dMaxSpeed(0), dPosDifference(0) {
        adWishSpeed[0] = adWishSpeed[1] = 0.0;
    }

    void CalcCircle(double dRadius, double dSpeed, double dTimestep);

    void CalcEight(double dRadius, double dSpeed, double dTimestep);

    void LogList(string sDatei);

    bool isRunning() {
      return bIsRunning;
    }

    void Start() {
      iter = CoordList.begin();
      bIsRunning = true;
    }

    void Stop() {
      bIsRunning = false;
    }

    void Proceed() {
      bIsRunning = true;
    }

    void CalcManeuverSpeed(double dX, double dY, double dW);

    double* GetManeuverSpeed();
};

#endif