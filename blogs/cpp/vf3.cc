#include <iostream>
using namespace std;
class A{
public:
  A(){cout<<"A::A()"<<endl;}
  virtual ~A(){cout<<"A::~A()"<<endl;}
private:
  int ma;
};
class B:public A{
public:
  B(){cout<<"B::B()"<<endl;}
  B(int a){cout<<"B::B()"<<endl;}
  virtual ~B(){cout<<"B::~B()"<<endl;}
  int mb;
};

int main(){
  B *pb = new B;
  pb = new B(3);
  return 0;
};
