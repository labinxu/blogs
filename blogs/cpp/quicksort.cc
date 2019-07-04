#include <iostream>
#include <vector>
using namespace std;


void quicksort(vector<int> &vints, int b, int e){
  if(b>e) return;
  int low = b;
  int high = e;
  int key = vints[b];
  while(low < high){
    while(low<high && vints[high]>key) high;
    vints[low]=vints[high];
  }
}
