#include<string>

using namespace std;

class Person{
public:
  Person(string sName, string sSurname, int iAge);
  ~Person();
  virtual string getName();
  string getSurname();
  int getAge();
  bool setAge(int iAge);
  virtual void printINFO();
private:
  string m_sName;
  string m_sSurname;
  int m_iAge;
};

class Student: public Person
{
public:
  Student(string sName, string sSurname, int iAge, unsigned int uiStudentID);
  ~Student();

  string getName() override;
  unsigned int getStudentID();
  void printINFO() override;

private:
  unsigned int m_uiStudentID;
};