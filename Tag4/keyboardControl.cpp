#include "keyboardControl.h"

using namespace std;

KeyboardControl* KeyboardControl::transferPointer = nullptr;

void KeyboardControl::transferFunction(){
  if(transferPointer !=nullptr){
    transferPointer->Step();
  }
}

KeyboardControl::KeyboardControl(vector<double> des_velocity, vector<double> act_velocity)
    : des_velocity(des_velocity), act_velocity(act_velocity), sim(), pid_controller(500,1850.0,0.0,0.04){  
    transferPointer = this;
    sim.Initialize(0.04, transferFunction);
}
double KeyboardControl::getLeft_desVelocity(){
  return des_velocity[0];
}
double KeyboardControl::getRight_desVelocity(){
  return des_velocity[1];
}

void KeyboardControl::increaseVelocity(){
  des_velocity[0] += 0.01;
  des_velocity[1] += 0.01;
}
void KeyboardControl::decreaseVelocity(){
  des_velocity[0] -= 0.01;
  des_velocity[1] -= 0.01;
}
void KeyboardControl::turnRight(){
  des_velocity[0] -= 0.005;
  des_velocity[1] += 0.005;
}
void KeyboardControl::turnLeft(){
  des_velocity[0] += 0.005;
  des_velocity[1] -= 0.005;
}
void KeyboardControl::turnZero(){
  des_velocity[0] = 0;
  des_velocity[1] = 0;
}
void KeyboardControl::limitTest(){
  for(int i = 0; i<2; ++i){
    if(des_velocity[i] > 0.5){
      des_velocity[i] = 0.5;
    }else if(des_velocity[i] < -0.5){
      des_velocity[i] = -0.5;
    }
  }
}
void KeyboardControl::Communicate(){
  sigprocmask(SIG_UNBLOCK, &sim.mask, nullptr);

  initscr();  
  nodelay(stdscr, TRUE); 
  cbreak();
  noecho();

  char input;
  printw("Please enter an input: ");
  bool running = true;
  while (running) {
    input = getch();

    if (input == 'q') {
            printw("\nExiting loop\n");
            running = false;
            refresh();
            endwin();
            break;
    }
    
    switch(input) {
        case 'w':
            increaseVelocity();
            break;
        case 's':
            decreaseVelocity();
            break;
        case 'a':
            turnLeft();
            break;
        case 'd':
            turnRight();
            break;
        case 'b':
            turnZero();
            break;
        default:
            break;
    }
    limitTest();
    clear();
    printw("Input is: %c\n", input);
    printw("Desired velocity is: %f and %f \n", getLeft_desVelocity(), getRight_desVelocity());
  }

  while (!running) {
    if(getLeft_desVelocity() != 0 || getRight_desVelocity() != 0){
      decreaseVelocity();
    }
      clear();
      printw("Current velocity is: %f and %f \n", getLeft_desVelocity(), getRight_desVelocity());
      refresh();
  }
  
  clear();
  printw("Program ending.");
  refresh();
  endwin();

  sigprocmask(SIG_BLOCK, &sim.mask, nullptr);
}

void KeyboardControl::Step(){
  double* pdInput = sim.GetInput();
  if(pdInput != nullptr){
    act_velocity[0] = pdInput[0];
    act_velocity[1] = pdInput[1];
  }
  
  vector<int> des_output(2); //if not initialize, will Segmentation fault
  for (int i = 0; i<2; ++i) { // turn to Signal
    pid_controller.CalculateU(des_velocity[i], act_velocity[i]);
    des_output[i] = 1500 + static_cast<int>(pid_controller.GetU());
    des_output[i] = max(1000, min(2000, des_output[i]));
  }

  sim.SetOutputs(des_output.data());
}
