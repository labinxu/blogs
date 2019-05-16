#include <iostream>
using namespace std;
void dosomething(){
  char dochars[10]="111111111";
  cout<<dochars<<endl;
}
void init(){
  char carray1[10]="";
  cout<<carray1<<endl;
  char *p = &carray1[2];
  cout<<p<<endl;
}

int main(){
  dosomething();
  init();
  return 0;
}
