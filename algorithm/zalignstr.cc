#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>

using namespace std;
class Solution {
public:
  string convert(string &s, int numRows){
    if(numRows<2){
      return s;
    }
    int len = s.size();
    int itemcols = 1+numRows-2;//3
    int y = 0;
    int x = 0;
    vector<vector<char>> sret(numRows);
    
    for(int i=0; i<len; ++i){
      if(x==0){
        sret[y++].push_back(s[i]);
        if(y%(numRows-1)==0){
          x=1;
        }
      }else{
        sret[y--].push_back(s[i]);
        if(y==0){
          x=0;
        }
      }

    }
    string nstr;
    for(auto v:sret){
      nstr+=string(v.begin(),v.end());
    }
    return nstr;
  }

  string convert1(string &s, int numRows) {
    if(numRows<2){
      return s;
    }
    int len = s.size();
    int itemcols = 1+numRows-2;//3
    int item_capacity = itemcols*numRows;
    int item_realcapcity = numRows+numRows-2;
    //cout<<"realcapcity:"<<item_realcapcity<<endl;
    //cout<<"itemcols:"<<itemcols<<endl;
    int totalcols=0;//(len/(2*numRows-2))*itemcols+lastrow;
    if(len<=item_realcapcity){
      totalcols=itemcols;
    }else{
      totalcols = (len/item_realcapcity+len%item_realcapcity)*itemcols;
    }

    //cout<<"totalcols"<<len<<": "<<totalcols<<endl;
    string pret(numRows*totalcols+1,0);
    string::iterator it = s.begin();
    for(auto col=0; col<totalcols; col++){
      for(auto row=0;row<numRows; row++){
        if(it == s.end()){
          continue;
        }
        auto pos = col+row*totalcols;
        if(col%itemcols==0){
          pret[pos]=*it;
          //    cout<<row<<":"<<col<<*it<<endl;
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
  string str="PAYPALISHIRING";
  Solution s;
  auto ret = s.convert(str, 4);
  cout<<"result string:"<<ret<<endl;
  return 0;
}
