#ifndef ROBOTCONTROL_H_
#define ROBOTCONTROL_H_

#include "PosEstimation.h"
#include "PIDController.h"
#include "Maneuver.h"
#include "InterfaceSIM.h"

class RobotControl {
private:
    double vIst[2];
    double vSoll[2];
    int iMicros[2];
    bool bIsActive;
    InterfaceSIM interface;
    PIDController motorR;
    PIDController motorL;
    Maneuver maneuver;
    PosEstimation posEstimation;

public:
    RobotControl();

    virtual ~RobotControl();

    void Communicate();

    void Step();

    bool isActive() {
        return bIsActive;
    }

    
    static RobotControl* transferPointer;
    static void transferFunction();
};

#endif