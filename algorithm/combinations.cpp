#include <vector>
#include <iostream>
#include <string>
#include <array>
using namespace std;
std::vector<string> vitems ={"tom","jim", "jiaojiao", "mark"};
std::vector<array<int, 4> > results;
void combinations(int l, std::array<int,4> &ret){
    if(l==ret.size()){
        ret[l-1] = 1;
        results.push_back(ret);
        ret[l-1] = 0;
        results.push_back(ret);
    }
    for(int i=l; i<vitems.size(); ++i){
        ret[i] = 1;
        combinations(i+1, ret);
        ret[i] = 0;
    }
}

void combinations_2(){
    for(int num=1;num<vitems.size();++num){
        std::vector<string> tmp;
        for(int i = 0; i<num; ++i){
            tmp.push_back(vitems[i]);
        }
    }
}
int main(){
    std::array<int, 4> result;
    for(int i=0; i< vitems.size(); ++i){
        result[i] = 1;
        combinations(i+1,result);
        result[i] = 0;
    }
    cout<<"numbers for results:"<<results.size()<<endl;
    for(auto ret:results){
        for(auto r:ret){
            cout<<r;
        }
        cout<<endl;
    }

}
