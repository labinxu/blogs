#include <iostream>
#include <string>
#include <cstring>
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string &s) {
    char bitmap[256];
    memset(bitmap, 0, 256);
    int len=0;
    int prelen=0;
    string prestr;
    string tmp;

    for(auto c:s){
      if(bitmap[c]==0){
        bitmap[c]=1;
        tmp+=c;
        ++len;
      }
      else{
        if (len > prelen){
          prelen = len;
          prestr = tmp;
        }
        tmp=c;
        len = 1;
        memset(bitmap, 0, 256);
        bitmap[c]=1;
      }
    }
    cout<<prelen<<": "<<prestr<<endl;
    return prelen;
  }
};
void test1(){
  string strval("bbbbb");
  Solution s;
  if(s.lengthOfLongestSubstring(strval) != 1){
    cout<<strval<<" ERROR: except 1"<<endl;
  }

}
void test2(){
  string strval("abcabcbb");
  Solution s;
  if (s.lengthOfLongestSubstring(strval) !=3){
    cout<<strval<<" ERROR: except 3"<<endl;
  }

}

void test3(){
  string strval("pwwkew");
  Solution s;
  if (s.lengthOfLongestSubstring(strval) !=3){
    cout<<strval<<" ERROR: except 3"<<endl;
  }

}
int main(){
  test1();
  test2();
  test3();
}
