#include <iostream>
using namespace std;
class IfValue{
public:
   operator int(){
     cout<<"operator int(): ";
     return 1;
   }

  operator bool(){
    cout<<"operator bool(): ";
    return 0;
  }
  operator double(){
    cout<<"operator double():";
    return 1.0;
  }
  operator float(){
     cout<<"operator float(): ";
     return 1.0f;
   }

};

int main(){
  if(1){
    cout<<"1 is true"<<endl;
  }
  else{
    cout<<"1 is false"<<endl;
  }
  if(0){
    cout<<"0 is true"<<endl;
  }
  else{
    cout<<"0 is false"<<endl;
  }
  if(1.0-1.0000000000000000001){
    cout<<"1.0000000 is true"<<endl;
  }
  else{
    cout<<"1.00000000 is false"<<endl;
  }
  if(-1){
    cout<<"-1 is true"<<endl;
  }
  else{
    cout<<"-1 is false"<<endl;
  }

  IfValue iv;
  if(1.0f==(float)iv){
    cout<<"iv is true"<<endl;
  }
  else{
    cout<<"iv is false"<<endl;
  }

  if(1.0-static_cast<double>(iv)){
     cout<<"iv == 1 is true"<<endl;
   }else{
     cout<<"iv == 1 is false"<<endl;
   }
}
