#include<iostream>
#include<string>
#include<cstring>
#include <sstream>

using namespace std;
class Solution {
public:
  string convert(string &s, int numRows) {

    int len = s.size();
    int itemcols = 1+numRows-2;
    int lastrow = len % (2*numRows-2)==0?0:1;
    int totalcols=(len/(2*numRows-2))*itemcols+lastrow;
    string pret(numRows*totalcols+1,0);
    string::iterator it = s.begin();
    for(auto col=0; col<totalcols; col++){
      for(auto row=0;row<numRows; row++){
        auto pos = col+row*totalcols;
        if(col%itemcols==0){
          pret[pos]=*it;
          cout<<row<<":"<<col<<*it<<endl;
            if (it != s.end()){
              ++it;
            }
          }
          else{
            if (row==numRows-(col%itemcols)-1){
              pret[pos]=*it;
              if(it != s.end()){
                ++it;
              }
            }
          }
      }

    }
    string tmpstr;
    for(auto v:pret){
      if(v!=0){
        tmpstr+=v;
      }
    }
    pret.swap(tmpstr);
    return pret;
  }
};

int main(){
  string str="LEETCODEISHIRING";
  Solution s;
  auto ret = s.convert(str, 4);
  cout<<"result string:"<<ret<<endl;
  return 0;
}
