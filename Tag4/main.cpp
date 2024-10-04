#include "keyboardControl.h"
#include <fstream>
#include <vector>

void readFile(const string& filename, vector<double>& w, vector<double>&y){
  fstream file;
  file.open(filename, ios::in);
  double w_, y_;
  if(file.is_open()){
    while(file >> w_ >> y_){
      w.push_back(w_);
      y.push_back(y_);
    }
    file.close();
  } 
}

void pid_test(){
  double result;
  vector<double> w, y;
  readFile("PIDControllerInput.txt", w, y);
  
  PIDController pid_controller(1000, 10, 0.10, 0.5);
  for(size_t i = 0; i < w.size(); ++i){
    pid_controller.CalculateU(w[i], y[i]);
    result = pid_controller.GetU();
    cout<< result<<endl;
  }
}


int main(){
    vector<double> s_velocity = {0.0, 0.0};
    vector<double> i_velocity = {0.0, 0.0};
    KeyboardControl con{s_velocity, i_velocity};
    //pid_test();
    con.Communicate();
    
    
    
    return 0;
}
