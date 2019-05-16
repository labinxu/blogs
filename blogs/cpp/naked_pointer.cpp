#include <iostream>
using namespace std;
// naked pointer free

void pass_naked_pointer1(int *p){
  cout<<"pass naked pointer: "<<*p<<endl;
  delete p;
  p = NULL;
}
void pass_naked_pointer2(int *&p){
  cout<<"pass reference naked pointer :"<<*p<<endl;
  delete p;
  p = NULL;
}
void pass_naked_pointer_with_obj_ref(int &p){
  cout<<"pass reference: "<<p<<endl;
  
}
void handler(){
  int *pint = new int(1);
  if(pint != NULL){
    //pass_naked_pointer1(pint);// core dump
    // pass_naked_pointer2(pint); // ok
    pass_naked_pointer_with_obj_ref(*pint);
  }

  if(pint != NULL){
    delete pint;
  }

}
int main(){
  handler();
}


