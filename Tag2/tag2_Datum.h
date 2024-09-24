// Date.h
#ifndef DATE_H
#define DATE_H

class Date
{
private:
  int m_day, m_month, m_year;
  //4. Date(int day, int month, int year);//should be public
public:
  Date(int day, int month, int year);
  bool isEqual(Date dd);
  int getDay();
  int getMonth();
  int getYear();
  int setDay(int day);
  int compare(Date dd);
};
#endif