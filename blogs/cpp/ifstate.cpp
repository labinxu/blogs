#include <iostream>
using namespace std;
struct AClass{
  operator bool(){
    return 1;
  }
};
int main(){
  AClass ac;
  if(ac){
    cout<<"ac value is true"<<endl;
  }else{
    cout<<"ac value is false"<<endl;
  }
  return 0;
}
