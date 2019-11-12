#include<iostream>
#include<limits>
using namespace std;
class Solution {
public:
  int reverse(int i) {

    //cout<<"int max "<<numeric_limits<int>::max()<<"\tint min:"<<numeric_limits<int>::min()<<endl;
  long remainder=i%10;
  int result=i/10;
  while(result){
    remainder=remainder*10+ result%10;
    //cout<<"result:"<<result<<" remainder:"<<remainder<<endl;
    result/=10;
  }
  if(remainder>numeric_limits<int>::max()
     || remainder<numeric_limits<int>::min()){
    return 0;
  }

  cout<<endl;
  return remainder;
}
};

int main(){
  Solution s;
  int input;
  cout<<"Enter a number:";
  cin>>input;
  int result = s.reverse(input);
  cout<<result<<endl;
  return 1;

};
