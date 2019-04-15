#include <iostream>
using namespace std;

int apb_1(int r, int c){
  if(c != 0){
    c <<= 1;
    return apb_1(r^c,r&c);
  }
  return r;
}

int apb_2(int a, int b)
{

  int c = 0;
  int r=0;
  int tmp = 0;
  r = a ^ b;
  c = a & b;
  tmp = 0;
  while(c!=0){
    c <<= 1;
    tmp = r^c;
    c = r & c;
    r = tmp;
  }
  return r;
}
int main(){
  int a=0;
  int b=0;
  while(1){
    cout<<"Enter a:";
    cin>>a;
    cout<<"Enter b:";
    cin>>b;
    cout<<"apb_1: "<<apb_1(a^b, b&a)<<endl;
    cout<<"apb_2: "<<apb_2(a,b)<<endl;;
  }
}
