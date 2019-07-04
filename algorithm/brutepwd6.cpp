#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
constexpr int BASE = 32;
constexpr int MAX_CHARS = 96;
std::vector<array<char, MAX_CHARS> > results4;
std::vector<array<char, MAX_CHARS> > results6;
void combinations(int l, std::array<char, MAX_CHARS> &ret){
    if(l==ret.size()){
        ret[l-1] = 1;
        auto sum = accumulate(ret.begin(), ret.end(), 0);
        do{
            if(sum==4){
                results4.push_back(ret);
                break;
            }else if( sum == 6){
                results6.push_back(ret);
                break;
            }
            ret[l-1] = 0;
            if(sum==4){
                results4.push_back(ret);
                break;
            }else if( sum == 6){
                results6.push_back(ret);
                break;
            }
            break;
        }while(true);
    }
    // if(100 == ret.size()){
    //     return;
    //}
    for(int i=l; i<MAX_CHARS; ++i){
        ret[i] = 1;
        combinations(i+1, ret);
        ret[i] = 0;
    }
}
void print_pwd4();
void print_pwd6();
int main(){
    std::array<char, MAX_CHARS> result;
    for(int i=0; i< MAX_CHARS; ++i){
        result[i] = 1;
        combinations(i+1, result);
        result[i] = 0;
    }
    print_pwd4();
    //print_pwd6();
    return 0;
}
void print_pwd4(){
    std::vector<array<char, 4> > rresults;
    for(auto r:results4){
        array<char, 4> rr;
        int k = 0;
        for (int i=0;i<r.size();i++){
            if(r[i] != 0){
                rr[k++]=i+BASE;
            }
        }
        for(auto v: rr){
            cout<<int(v)<<" ";
        }
        cout<<"\n";
        rresults.push_back(rr);
    }
}
void print_pwd6(){
    std::vector<array<char, 6> > rresults;
    for(auto r:results6){
        array<char, 6> rr;
        for (int i=0;i<r.size();i++){
            int k = 0;
            if(r[i] != 0){
                rr[k++]=char(i+32);
                cout<<i+32<<" ";
            }
        }
        cout<<"\n";
        rresults.push_back(rr);
    }
}
void combinations(){
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
