#include<iostream>

using namespace std;

int factorialIter(int num){
  int res = 1;
  for(int i = num; i>0; --i){
    res *= i;
  }
  return res;
}

int factorialRec(int num){
  if(num==0 || num ==1 ){
    return 1;
  }
  return num * factorialRec(num-1);
}

int main(){
  int num = 5;
  int iter_res = factorialIter(num);
  int rec_res = factorialRec(num);
  cout<<iter_res<<endl;
  cout<<rec_res<<endl;
  return 0;
}