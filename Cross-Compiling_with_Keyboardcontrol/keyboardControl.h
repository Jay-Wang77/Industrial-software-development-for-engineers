#ifndef KEYBOARD_CONTROL_H
#define KEYBOARD_CONTROL_H

#include<iostream>
#include<vector>
#include <iostream>
#include "PIDController.h"

#include "ncurses/curses.h"
#include "InterfaceHW/InterfaceHW.h"
#include <pigpio.h>
#include <unistd.h>

using namespace std;

class KeyboardControl{
public:
	KeyboardControl();
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
  double des_velocity[2];
  double act_velocity[2];
  InterfaceHW interface;
  PIDController pid_controller;
};

#endif
