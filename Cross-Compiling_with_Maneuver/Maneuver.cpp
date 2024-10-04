#include "Maneuver.h"

using namespace std;

Maneuver::Maneuver() {
  Coord(0.0, 0.0, 0.0);
  iter = CoordList.begin();
  bIsRunning = false;
  dMaxSpeed = 0.5;
  dPosDifference = 0.02;
  adWishSpeed[0] = 0.0;
  adWishSpeed[1] = 0.0;
}

Maneuver::~Maneuver(){}

void Maneuver::CalcCircle(double dRadius, double dSpeed, double dTimestep){

  CoordList.clear();

  for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){
    double x = dRadius * sin(counter * dSpeed / dRadius * dTimestep);
    double y = dRadius *(1- cos(counter * dSpeed / dRadius * dTimestep));
    double v = dSpeed;
    CoordList.push_back(Coord(x, y, v));
  }
  
}

void Maneuver::CalcEight(double dRadius, double dSpeed, double dTimestep){
  
  CoordList.clear();

  for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){
    double x1 = dRadius * sin(counter * dSpeed / dRadius * dTimestep);
    double y1 = dRadius *(1- cos(counter * dSpeed / dRadius * dTimestep));
    double v1 = dSpeed;
    CoordList.push_back(Coord(x1, y1, v1));
  }

  for(int counter = 1; counter<(int)((2*M_PI)/((dSpeed/dRadius)*dTimestep)); counter++){
    double x2 = dRadius * sin(counter * dSpeed / dRadius * dTimestep);
    double y2 = (-dRadius) *(1- cos(counter * dSpeed / dRadius * dTimestep));
    double v2 = dSpeed;
    CoordList.push_back(Coord(x2, y2, v2));
  }
}



void Maneuver::CalcManeuverSpeed(double dX, double dY, double dW){

  // Positionsvergleich
  if(!CoordList.empty() && abs(iter->dX - dX) <= dPosDifference && abs(iter->dY - dY) < dPosDifference){
      iter++;
  }

  // Überprüfen, ob das Ende der Liste erreicht wurde
  if(iter == CoordList.end()){ //maneuver end
    adWishSpeed[0] = 0.0;
    adWishSpeed[1] = 0.0;
    Stop();
  }else{

    // Winkeldifferenz berechnen
    double phi = atan2(iter->dY - dY, iter->dX - dX);
    double w_diff = phi - dW;
    if(w_diff <= -M_PI){
      w_diff += 2* M_PI;
    }else{ if(w_diff > M_PI) //!!! critial mistake
      w_diff -= 2* M_PI;
    }

    // Rotationsanteil bestimmen
    double dRot = w_diff * 2; 
    if(dRot > 0.5){
      dRot = 0.5;
    }else if(dRot< -0.5){
      dRot = -0.5;
    }

    // Translationsanteil
    double dTra = iter->dV;

    // Geschwindigkeitsanteile überprüfen
    if(dTra * dRot > 0.0){
      if(dTra + dRot > dMaxSpeed){
        dTra = dMaxSpeed - dRot;
      }else if(dTra + dRot < -dMaxSpeed){
        dTra = -dMaxSpeed - dRot;
      }
    }else if(dTra * dRot < 0.0){
      if(dTra - dRot > dMaxSpeed){
        dTra = dMaxSpeed + dRot;
      }else if(dTra - dRot < -dMaxSpeed){
        dTra = -dMaxSpeed + dRot;
      }
    }
    adWishSpeed[0] = dTra + dRot;
    adWishSpeed[1] = dTra - dRot;
  }
}

double* Maneuver::GetManeuverSpeed(){
  return adWishSpeed;
}
