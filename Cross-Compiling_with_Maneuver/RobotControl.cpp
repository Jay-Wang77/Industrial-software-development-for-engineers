#include "RobotControl.h"

RobotControl* RobotControl::transferPointer;

void RobotControl::transferFunction(){
  transferPointer->Step();
}

RobotControl::RobotControl(): vIst{0.0, 0.0}, vSoll{0.0, 0.0}, iMicros{1500, 1500}, bIsActive{true}, motorL(500.0,1850.0,0.0,0.04), motorR(500.0,1850.0,0.0,0.04), interface(), maneuver(), posEstimation(){
  transferPointer = this;
  interface.Initialize(0.04);
  interface.SetTimerfunction(0, 0.04, (&transferFunction));
}

RobotControl::~RobotControl(){}

void RobotControl::Communicate(){

  char init_input;
  bool running = true;

  std::cout<<"whether a new autonomous Maneuver should be performed? (1 or 2)"<<endl;
  std::cin>>init_input;

  if(init_input != '1' ){
    bIsActive = false;
  }else if(init_input == '1' ){

    std::cout<<"enter the Radius: "<<endl;
    double Radius;
    cin>>Radius;

    std::cout<<"enter the velocity: "<<endl;
    double Velocity;
    cin>>Velocity;

    std::cout<<"which shape you want to make: Kreis(1) or Acht(2)? "<<endl;
    int shape;
    cin>>shape;
    double dTimestep = 0.04;

    if(shape == 1){
      maneuver.CalcCircle(Radius, Velocity, dTimestep);
    }else if(shape == 2){
      maneuver.CalcEight(Radius, Velocity, dTimestep);
    }else if(shape != 1 && shape != 2){
      cout<<"wrong input!"<<endl;
    }
  }
  PosEstimation posestimation;
  posEstimation.Reset();

  initscr();  
  nodelay(stdscr, TRUE); 
  noecho();

  int ch; 
  printw("enter s for start, p for pause, c for continue: ");
  refresh();
  while (ch!='q') {
    ch = getch();
    if (ch == ERR) {
      continue;
    }
   
    switch(ch) {
        case 's': // start
            maneuver.Start();
            printw("start\n");
            break;
        case 'p': // pause
            maneuver.Stop();
            printw("pause\n");
            break;
        case 'c': // continue
            maneuver.Proceed();
            printw("continue\n");
            break;
        default:
            printw("please enter again\n");
            break;
    }
  }
  maneuver.Stop();
  clear();
  endwin();
  return;
}

void RobotControl::Step(){
  double* pdInput = interface.GetInput();
  vIst[0] = pdInput[0];
  vIst[1] = pdInput[1];


  if(maneuver.isRunning()){
    double dTimestep = 0.04;

    // get x y w
    posEstimation.PredictPosition(vIst[0], vIst[1],dTimestep); 
    double* state = posEstimation.GetPosition();

    // get wheel speed
    maneuver.CalcManeuverSpeed(state[0], state[1], state[2]);
    double* speeds = maneuver.GetManeuverSpeed();

    vSoll[0] = speeds[0];
    vSoll[1] = speeds[1];

    // after PID
    motorR.CalculateU(vSoll[0], vIst[0]);
    motorL.CalculateU(vSoll[1], vIst[1]);

    
    iMicros[0] = 1500 + static_cast<int>(motorR.GetU());
    iMicros[0] = max(1000, min(2000, iMicros[0]));
    iMicros[1] = 1500 + static_cast<int>(motorL.GetU());
    iMicros[1] = max(1000, min(2000, iMicros[1]));

  }else{
    iMicros[0] = 1500;
    iMicros[1] = 1500;
  }

  interface.SetOutputs(iMicros);
  
}
