// Date.cpp
#include "tag2_Datum.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Date::Date(int day, int month, int year)
{
  m_day = day; m_month = month; m_year = year;
}

int Date::getDay() {return m_day;}//1. missing class name
int Date::getMonth() {return m_month;}
int Date::getYear() {return m_year;}
int Date::setDay(int day) {return m_day = day;}
bool Date::isEqual(Date dd)
{
  if(m_day==dd.m_day && m_month==dd.m_month && m_year==dd.m_year)
    return true;
    return false;
}
int Date::compare(Date dd){
  if(m_year == dd.m_year){
    if(m_month > dd.m_month){
      return 1;
    }else if(m_month < dd.m_month){
      return -1;
    }else{
      if(m_day > dd.m_day){
        return 1;
      }else if(m_day < dd.m_day){
        return -1;
      }else{
        return 0;
      }
    }
  }else if(m_year > dd.m_year){
      return 1;
  }else if(m_year < dd.m_year){
      return -1;
  }
  return 0;
}
int randomDate(int min, int max){
  return rand() % (max - min + 1) + min;
}

int main()
{
  srand(time(NULL));
  int dd1 = randomDate(1, 30);
  int mm1 = randomDate(1, 12);
  int yy1 = randomDate(1970, 2030);
  
  int dd2 = randomDate(1, 30);
  int mm2 = randomDate(1, 12);
  int yy2 = randomDate(1970, 2030);
  Date d1 = Date(dd1, mm1 , yy1);
  Date d2 = Date(dd2, mm2 , yy2);
  if(dd1<=30 && dd1>0 && dd2<=30 && dd2>0){
    if(mm1<=12 && mm1>0 && mm2<=12 && mm2>0){
      if(yy1<2030 && yy1 > 1970 && yy2<2030 && yy2 > 1970){
        bool tf = d2.isEqual(d1); //3. isequal should be isEqual
        int res = d1.compare(d2);
        cout<< d1.getDay() <<"-"<<d1.getMonth() << "-"<< d1.getYear()<<endl;
        cout<< d2.getDay() <<"-"<<d2.getMonth() << "-"<< d2.getYear()<<endl;
        cout << tf <<", "<< res<<endl;
      }
    }
  }
  //Date d1 = Date(2,2,2011);
  //d1.setDay(15); //2. m_day is private
  //Date d2 = Date(15,2,2011);
  //bool tf = d2.isEqual(d1); //3. isequal should be isEqual
  //int res = d1.compare(d2);
  //cout <<tf<<", "<< res<<endl;
  return 0;//5. return 0
}