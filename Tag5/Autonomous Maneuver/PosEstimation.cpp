#include "PosEstimation.h"
#include <iostream>

using namespace std;

PosEstimation::PosEstimation(): x(3, 0.0), dVelAverage(0.0){}
PosEstimation::PosEstimation(vector<double> x, double dVelAverage){
  this->x = x;
  this->dVelAverage = dVelAverage;
}

PosEstimation::~PosEstimation(){};

void PosEstimation::PredictPosition(double dSpeedR, double dSpeedL, double dTimestep){
  x[0] += dVelAverage * dTimestep * cos(x[2]);
  x[1] += dVelAverage * dTimestep * sin(x[2]);
  //cout<<dVelAverage<<endl;

  x[2] += dTimestep * ((dSpeedR - dSpeedL) / 0.23); 

  x[2] = fmod(x[2], 2*M_PI);
  if (x[2] > M_PI)
    x[2] -= 2*M_PI;
  else if (x[2] <= -M_PI)
    x[2] += 2*M_PI;

  dVelAverage = (dSpeedL + dSpeedR) / 2;
  //cout<<dVelAverage<<endl;
  
}


double* PosEstimation::GetPosition(){
  return x.data();
}

void PosEstimation::Reset(){
  for(int i = 0; i<x.size(); ++i){
    x[i] = 0;
  }
}