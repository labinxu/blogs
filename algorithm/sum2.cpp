#include<iostream>
#include<vector>

#include<map>
using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode headnode(0);
    ListNode *result=&headnode;
    auto carry=0;
    auto lastcarry=0;
    while(l1){
      if(l2){
        auto value = l1->val+l2->val;
        if (value >= 10){
          carry=1;
          value -= 10;
        }else{
          carry=0;
        }
        ListNode *tmp=new ListNode(value+lastcarry);
        lastcarry=carry;
        result->next=tmp;
        result = result->next;
        l1=l1->next;
        l2=l2->next;
      }
    }
    return headnode.next;
  }

  vector<int> twoSum2(vector<int>& nums, int target) {
    cout<<"twoSum2"<<endl;
    map<int,int> v2i;
    vector<int> vi;
    for(auto i = 0; i<nums.size(); ++i){
      v2i[nums[i]]=i;
    }
    for(auto i=0; i<nums.size(); ++i){
      auto it=v2i.find(target-i);
      if (it != v2i.end()){
        if(it->second != i){
        vi.push_back(nums[i]);
        vi.push_back(it->second);
        }
        cout<<"["<<i<<" "<<it->second<<"]"<<endl;
      }
    }
    return vi;
  }

  vector<int> twoSum(vector<int>& nums, int target) {

    for (auto i=0;i<nums.size();++i){
      auto sec=target-nums.at(i);
      for(auto j=i+1;j<nums.size();++j){
        if(nums.at(j) == sec) {
          cout<<"["<<i<<" "<<j<<"]"<<endl;
        }
      }
    }
    return vector<int>();
  }
  
};
void ShowList(ListNode *l){
  while(l!=nullptr){
    cout<<l->val<<"\t";
    l=l->next;
  }
  cout<<endl;
}
int main()
{
  vector<int> nums={2,7,11,15,2};
  int target=0;
  // while(1){
  //   cin>>target;
  //   Solution s;
  //   s.twoSum(nums, target);
  //   s.twoSum2(nums, target);
  //}

  ListNode *l1=new ListNode(2);
  ListNode *pl1=l1;
  pl1->next=new ListNode(4);
  pl1=pl1->next;
  pl1->next=new ListNode(3);

  // cout<<l1->val<<l1->next->val<<l1->next->next->val;
  // cout<<endl;
  ListNode *l2=new ListNode(5);
  ListNode *pl2=l2;
  l2->next=new ListNode(6);
  pl2=pl2->next;
  pl2->next=new ListNode(4);
  Solution s;
  auto ret=s.addTwoNumbers(l1, l2);
  ShowList(ret);
}
