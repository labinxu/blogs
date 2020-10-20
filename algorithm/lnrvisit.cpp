#include <iostream>
using namespace std;
typedef struct TNode{
  int val;
  TNode *left;
  TNode *right;
}TNode;

void lnrvisit(TNode *node){
  if(node!=nullptr){
    lnrvisit(node->left);
    cout<<node->val<<endl;
    lnrvisit(node->right);
  }
}

int main(){
  TNode * r = new TNode{0,nullptr,nullptr};
  r->val=1;
  auto left = new TNode{0,nullptr,nullptr};
  left->val = 2;
  // left->left = nullptr;
  // left->right = nullptr;
  r->left=left;
  auto right = new TNode{0,nullptr,nullptr};
  right->val = 3;
  r->right = right;
  // right->left = nullptr;
  // right->right=nullptr;
  lnrvisit(r);
  return 0;
}
