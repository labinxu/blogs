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
    std::vector<vector<int> > results;
    std::vector<int> r,l;
    l.push_back(1);
    r.push_back(0);
    results.push_back(l);
    results.push_back(r);
    for(int i = 1; i < vitems.size(); ++i){
        auto len = results.size();
        for(int j=0; j<len; ++j){
           auto tmp = results[j];
           results[j].push_back(1);
           tmp.push_back(0);
           results.push_back(tmp);
        }
    }

    cout<<"number of results "<<results.size()<<endl;
    for(auto r: results){
        for(auto rr: r){
            cout<<rr;
        }
        cout<<endl;
    }

}
int main(){
    combinations_2();
    return 0;
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
