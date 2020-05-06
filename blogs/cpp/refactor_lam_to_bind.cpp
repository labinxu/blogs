#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

class LamToBind{
public:
  void lToB(){
    auto callback = [this](int a,int b){
                      func(a,b);
                    };
    auto callback2=bind(&LamToBind::func,this,_1,_2);

    callback(1,2);
    callback2(3,4);
  }
  void func(int a,int b){
    cout<<"func a:"<<a<<"; b:"<<b<<endl;
  }
};
int main(){
  LamToBind lb;
  lb.lToB();
  return 0;
};
