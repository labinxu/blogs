#include<iostream>
using namespace std;
struct A{
  virtual ~A(){cout<<"destructor A"<<endl;}
  virtual void f1(){cout<<"A::f1"<<endl;}

};
struct B :public A{
  ~B(){cout<<"destructor B"<<endl;}
};

int main(){
  A *pb = new B;
  delete pb;
  return 0;
}
