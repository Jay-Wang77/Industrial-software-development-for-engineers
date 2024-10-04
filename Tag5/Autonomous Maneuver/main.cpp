#include <fstream>
#include <vector>
#include <iostream>
#include "PosEstimation.h"
#include "Maneuver.h"
#include "RobotControl.h"

using namespace std;

void readFile(const string& filename, vector<double>& lv, vector<double>&rv, vector<double>& t){
  fstream file;
  file.open(filename, ios::in);
  double lv_, rv_, t_;
  if(file.is_open()){
    while(file >> lv_ >> rv_ >> t_){
      lv.push_back(lv_);
      rv.push_back(rv_);
      t.push_back(t_);
    }
    file.close();
  } 
  //for (size_t i = 0; i < w.size(); ++i) {
        //std::cout << "w: " << w[i] << ", y: " << y[i] << std::endl;
  //}
}

void posEstimation_test(){
  vector<double> lv,rv,t;
  readFile("PosEstimationInput.txt", lv,rv, t);
  PosEstimation estimate;
  
  for(size_t i = 0; i < lv.size(); ++i){
    estimate.PredictPosition(lv[i], rv[i], t[i]);
    double* result = estimate.GetPosition();
    std::cout << result[0] << " " << result[1] << " " << result[2] << std::endl;;
  }
}

int main(){
    //Maneuver maneuver;
    //posEstimation_test();
    
    //maneuver.CalcCircle(2.0, 0.3, 0.04);
    //maneuver.LogList("LogFileCircle.txt");

    //maneuver.CalcEight(5.0, 1.0, 10.0);
    //maneuver.LogList("LogFileEight.txt");
    RobotControl robotControl;
    while(robotControl.isActive()){
      robotControl.Communicate();
      
    }
    
    return 0;
}