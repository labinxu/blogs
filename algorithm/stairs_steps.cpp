#include <iostream>
using namespace std;
int steps(int n){
  if (n==1){
    cout<<"1 ";
    return 1;
  }
  if (n==2){
    cout<<"2 ";
    return 2;
  }
  return steps(n-1)+steps(n-2);
}

int main(){
  int stairs = 0;
  while(1){
    cout<<"Input number of stairs:";
    cin>>stairs;
    if (stairs<=0){
      break;
    }
    cout<<"Steps result: "<<steps(stairs)<<endl;
  }
  int *p = nullptr;
  *p = 1;
  return 0;
}

