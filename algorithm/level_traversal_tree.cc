#include<iostream>
using namespace std;
struct Node
{
  Node(int v):value(v),left(nullptr),right(nullptr){}
  int value;
  Node *left;
  Node *right;
};

int main(){
  return 0;
}
