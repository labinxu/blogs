#include <iostream>
using namespace std;
class A{
public:
  virtual void af1(){cout<<"A::af1"<<endl;}
  virtual void af2(){cout<<"A::af2"<<endl;}
};

class B{
public:
  virtual void bf1(){cout<<"B::bf1"<<endl;}
  virtual void bf2(){cout<<"B::bf2"<<endl;}
};
class C: public A,public B{
public:
  void af1(){cout<<"C::af1"<<endl;}
  void bf1(){cout<<"C::bf1"<<endl;}
  virtual void  cf1(){cout<<"C::cf1"<<endl;}
};

// namespace nv{
//   class A{
//   public:
//     void f1(){cout<<"A::f1"<<endl;}
//   };

//   class B{
//   public:
//     void f1(){cout<<"B::f2"<<endl;}
//   };
//   class C: public A,public B{
//   public:
//     using A::f1;
//   };
// }

int main(){
  C *pc = new C;
  pc->af1();
  pc->C::bf1();
  return 0;
};
