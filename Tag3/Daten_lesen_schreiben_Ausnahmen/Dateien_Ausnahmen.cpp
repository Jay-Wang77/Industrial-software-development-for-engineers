#include<iostream>
#include<fstream>
#include <string>
using namespace std;

class nofileException : public exception {
public:
    virtual const char* what() const throw() {
        return "Die Datei existiert nicht";
    }
};

void read_file(string Dateiname){
  ifstream file(Dateiname);
  if(file.is_open()){
    string buf;
    while(getline(file,buf)){
      cout<<buf<<endl;
    }
    file.close();
  }else{
    throw nofileException();
  }
}

void write_file(string Dateiname){
  ofstream file(Dateiname, ios::app);
  if(file.is_open()){
    string input;
    while(1){
      getline(cin, input);
      if(input == "exit"){
        break;
      }
      file << input << endl;
    }
    file.close();
  }else{
    cout<<"sorry"<<endl;
  }
}

int main(){
  string filename;
  cout<< "geben Namen ein: ";
  getline(cin,filename);
  try{
    read_file(filename);
    cout<< "geben Inhalt ein: ";
    write_file(filename);
    cout<< "Inhalt ist: ";
    read_file(filename);
    return 0;    
  }catch(nofileException(e)){
    cout<<e.what()<<endl;
  }

}