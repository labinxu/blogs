#include<iostream>
#include<limits>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
  int myAtoi(string input) {
    bool begin=false;
    char csig=0;
    string snumer;
    for(auto i:input){
      if(i=='-' ||i=='+'){
        if(begin){
          break;
        }
        csig=i;
        begin=true;
      }else if(i==' '){
        if(begin){
          break;
        }

        if(snumer.empty()){
          continue;
        }else{
          break;
        }
      }else if(i<='9' && i>='0'){
        begin=true;
        snumer+=i;
        continue;
      }
      else{
        break;
      }
    }
    long result=0;
    if(snumer.empty()){
      return result;
    }else{
      for(auto v: snumer){
        if(csig=='-'){
          if((0-result) < numeric_limits<int>::min()){
            return numeric_limits<int>::min();
          }
        }

        if (result>numeric_limits<int>::max()){
          return numeric_limits<int>::max();
        }
        result = result*10+(v-48);

      }
    }
    if(csig=='-'){
      result=0-result;
    }
    if(result>numeric_limits<int>::max()){
      return numeric_limits<int>::max();
    }else if(result<numeric_limits<int>::min()){
      return numeric_limits<int>::min();
    }
    return result;
  }
};

int main(){
  std::vector<string> teststrs={"   -42",
                                "+-2",
                                "42",
                                "words and 987",
                                "4193 with words",
                                "-91283472332"};

  Solution s;
  for(auto strnumer: teststrs){
    int ret = s.myAtoi(strnumer);
    cout<<"origin "<<strnumer<<":"<<ret<<endl;
  }
  return 0;
}

