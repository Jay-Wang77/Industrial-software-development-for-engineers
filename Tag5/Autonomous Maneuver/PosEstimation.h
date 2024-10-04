#ifndef POSESTIMATION_H_
#define POSESTIMATION_H_
#include<cmath>
#include<vector>

using namespace std;

class PosEstimation {
private:
    vector<double> x;           
    double dVelAverage; 
public:
    PosEstimation();
    ~PosEstimation();
    PosEstimation(vector<double> x, double dVelAverage);

    void Reset();

    void PredictPosition(double dSpeedL, double dSpeedR, double dTimestep);

    double* GetPosition();

    void posEstimation_test();
};


#endif