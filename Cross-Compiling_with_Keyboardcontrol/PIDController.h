#ifndef PIDCONTROLLER
#define KEYBOARD_CONTROL_H
#include<iostream>

class PIDController{
public:
  PIDController(double Kp, double Ki, double Kd, double Ta);
  void CalculateU(double dW, double dY);
  double GetU();
private:
  double dKp;
  double dKi;
  double dKd;
  double dTa;
  double dEsum = 0.0;
  double deold = 0.0;
  double dU = 0.0;
};

#endif
