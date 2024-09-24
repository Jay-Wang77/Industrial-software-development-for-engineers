#include<iostream>
#include<list>

using namespace std;

struct coord{
  float x;
  float y;
  coord(float m_x, float m_y):x(m_x), y(m_y){}
};

void printlist(const list<coord> *list){
  for(auto it = list->begin(); it!=list->end();it++){
    cout<<"X: "<<it->x <<", Y: "<<it->y<<endl;
  }
}

void delcoords(list<coord> &list){
  for(auto it = list.begin(); it!=list.end();){
    if(it->x < it->y){
      it = list.erase(it);// del coords;
    }else{
      ++it;
    }
  }
}
float random(const int min, const int max){
  return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

int main(){
  srand(static_cast<unsigned>(time(NULL))); // 生成随机小数
  list<coord> l1;
  for (int i = 0; i < 10; ++i) {
      l1.emplace_back(random(0, 100), random(0, 100));
  }
  cout<<"list 1 is: "<<endl;
  printlist(&l1);
  cout<<endl;

  list<coord> l2(l1.begin(), l1.end());
  delcoords(l1);
  cout<<"the coords are deleted: "<<endl;
  printlist(&l1);
  cout<<endl;
  cout<<"list 2 is: "<<endl;
  printlist(&l2);
}


