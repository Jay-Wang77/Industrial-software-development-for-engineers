#include<iostream>
#include<memory>
#include "tag2_Vererbung.h"
using namespace std;


Person::Person(string sName, string sSurname, int iAge): m_sName(sName), m_sSurname(sSurname), m_iAge(iAge) {
}

Person::~Person(){}

string Person::getName(){
  return m_sName;
}

string Person::getSurname(){
  return m_sSurname;
}

int Person::getAge(){
  return m_iAge;
}

bool Person::setAge(int iAge){
  if (iAge >= 0) {
    m_iAge = iAge;
    return true;
  }
  return false;
}
void Person::printINFO(){
  cout<< m_sName <<" "<<  m_sSurname <<" "<<  m_iAge << endl;
}

Student::Student(string sName, string sSurname, int iAge, unsigned int uiStudentID):Person(sName, sSurname, iAge), m_uiStudentID(uiStudentID){}
Student::~Student(){}

string Student::getName(){
  return "Student " + Person::getName();
}

unsigned int Student::getStudentID(){
  return m_uiStudentID;
}

void Student::printINFO(){
  cout<< getName() <<" "<< getSurname() <<" "<< getAge() <<" "<< m_uiStudentID << endl;
}

int main(){
  Person p1("Alice", "A",18);
  cout << "Person Name: " << p1.getName() << endl;

  Student s1("Bob","b",20,123457);
  cout << "Student Name: " << s1.getName() << endl;
  cout << "Student ID: " << s1.getStudentID() << endl;

  shared_ptr<Person> s3 = make_shared<Person>("Cat", "C",28);
  s3->printINFO();
  shared_ptr<Person> s4 = make_shared<Student>("Cat", "C",28,12345);
  s4->printINFO();
  return 0;
}