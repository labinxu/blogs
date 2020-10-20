#include <iostream>
using namespace std;
int main(){
    int a = 2;
    int b = 3;
    while(1){
    cout<<"Enter a:";
          cin>>a;
    cout<<"Enter b:";
          std::cin>>b;
    int c = a ^ b;
    cout<<a<<"^"<<b<<"="<<c<<endl;
    int d = a & b;
    cout<<a<<"&"<<b<<"="<<d<<endl;
    int r = a | b;
    while(d != 0){
        cout<<"r = "<<r<<endl;
        r<<=1;
        r |= c;
        cout<<"d = "<<d<<"c = "<<c<<"r = "<<r<<endl;
        d = c & d;
        c = c ^ r;
    }
    cout<<"result :"<<r<<endl;
    }
}

