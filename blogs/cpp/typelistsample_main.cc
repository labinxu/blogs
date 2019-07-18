#include <iostream>
#include "typelistsample.hpp"
using namespace std;
int main()
{
  typedef typelist<int, float, double> typerepo;
  cout<<"size:"<<typerepo::size<<endl;
}
