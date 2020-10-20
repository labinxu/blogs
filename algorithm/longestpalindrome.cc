#include<iostream>
#include<string>
#include<list>
using namespace std;
class Solution {
public:
  string longestPalindrome(string &str) {
    const int len=str.size()*2+1;
    string tmpstr(len,0);
    int pArr[len]={0};
    int index=0;
    for(auto i=0;i<len;i++){
      tmpstr[i]= i%2==0?'#':str[index++];
    }
    int C=-1;
    int R=-1;
    for(int i=0; i<len;++i){
      
    }
    return tmpstr;
  }
  string longestPalindrome1(string &str) {
    if(str.size()>1000){
      return "";
    }

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
            step=1;
            break;
          }
          if (!(i+step <= j-step)){
            string tmp(str.substr(i , j-i+1));
            if (tmp.size()>=rest.size()){
              rest.swap(tmp);
            }
          }
        }
      }
    }
    if(rest.empty()){
      return string(1, str[0]);
    }
    return rest;
  }
};

int main(){
  string str="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  string str2="abdd";
  Solution s;
  auto palinddrome=s.longestPalindrome(str2);
  cout<<"longestPalindrome: "<<palinddrome<<endl;
  return 0;
}
