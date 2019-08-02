#include <iostream>
using namespace std;
namespace v{
class A{
public:
  virtual void af1(){cout<<"A::af1"<<endl;}
  virtual void af2(){cout<<"A::af2"<<endl;}
};

class B{
public:
  virtual void bf1(){cout<<"B::bf2"<<endl;}
  virtual void bf2(){cout<<"B::bf2"<<endl;}
};
class C: public A,public B{
// public:
//   virtual void bf2(){cout<<"C::bf2"<<endl;}

};
}
namespace nv{
  class A{
  public:
    void f1(){cout<<"A::f1"<<endl;}
  };

  class B{
  public:
    void f1(){cout<<"B::f2"<<endl;}
  };
  class C: public A,public B{
  public:
    using A::f1;
  };
}

int main(){
  v::C *pc = new v::C;
  return 0;
};
