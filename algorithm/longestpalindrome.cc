#include<iostream>
#include<string>
#include<list>
using namespace std;
class Solution {
public:
  string longestPalindrome(string &str) {
    string rest;
    for(int i=0; i<str.size(); ++i){
      int step=1;
      for(int j=str.size()-1;j>=0;j--){
        if(i>=j){
          break;
        }
        if(str[i]==str[j]){
          while((i+step) <= (j-step)){
            if(str[i+step]==str[j-step]){
              step++;
              continue;
            }
            break;
          }

          if (i+step >= j-step){
            //cout<<i<<":"<<j<<endl;
            string tmp(str.substr(i , j-1+1));
            //cout<<str.substr(i, j-i+1)<<endl;
            if (tmp.size()>rest.size()){
              rest.swap(tmp);
            }

          }
        }
      }
    }
    return rest;
  }
};

int main(){

  string str="babaf";

  Solution s;
  auto palinddrome=s.longestPalindrome(str);
  cout<<"longestPalindrome: "<<palinddrome<<endl;
  return 0;
}
