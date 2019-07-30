#include<iostream>
using namespace std;
struct A{
  virtual void f1(){cout<<"A::f1()"<<endl;}
};
struct B :public A{
  virtual void f1(){cout<<"B::f1()"<<endl;}
};

int main(){
  A *pA = new B;
  (*pA).f1();
  A(*pA).f1();
  B b;
  A(b).f1();
  A *bref=&b;
  bref->f1();
  return 0;
}
