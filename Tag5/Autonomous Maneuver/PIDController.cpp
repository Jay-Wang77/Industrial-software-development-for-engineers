#include "PIDController.h"

using namespace std;

PIDController::PIDController(double Kp, double Ki, double Kd, double Ta){
  dKp = Kp;
  dKi = Ki;
  dKd = Kd;
  dTa = Ta;
}
void PIDController::CalculateU(double W, double dY){
  double ek = W - dY;
  dEsum += ek;
  dU = dKp * ek + dKi * dTa * dEsum + dKd * ((ek - deold) / dTa);
  deold = ek;
}
double PIDController::GetU(){
  return dU;
}
