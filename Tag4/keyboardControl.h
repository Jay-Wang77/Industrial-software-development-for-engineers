#ifndef KEYBOARD_CONTROL_H
#define KEYBOARD_CONTROL_H

#include<iostream>
#include<vector>
#include <ncurses.h>
#include "InterfaceSIM.h"
#include "PIDController.h"

class KeyboardControl{
public:
  KeyboardControl(vector<double> des_velocity, vector<double> act_velocity);
  void Communicate();
  void Step();
  double getLeft_desVelocity();
  double getright_desVelocity();
  void increaseVelocity();
  void decreaseVelocity();
  void turnLeft();
  void turnRight();
  void turnZero();
  void limitTest();

  static KeyboardControl* transferPointer;
  static void transferFunction();
private:
  vector<double> des_velocity;
  vector<double> act_velocity;
  InterfaceSIM sim;
  PIDController pid_controller;
};

#endif