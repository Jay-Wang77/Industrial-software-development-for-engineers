#include <fstream>
#include <vector>
#include <iostream>
#include "PosEstimation.h"
#include "Maneuver.h"
#include "RobotControl.h"


using namespace std;



int main(){
    //Maneuver maneuver;
    //posEstimation_test();
    
    //maneuver.CalcCircle(2.0, 0.3, 0.04);
    //maneuver.LogList("LogFileCircle.txt");

    //maneuver.CalcEight(5.0, 1.0, 10.0);
    //maneuver.LogList("LogFileEight.txt");
	gpioInitialise();
    RobotControl robotControl;
    while(robotControl.isActive()){
      robotControl.Communicate();
      
    }
    gpioTerminate();
    
    return 0;
}
