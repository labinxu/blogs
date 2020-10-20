#include<iostream>
#include<limits>
#include <algorithm>
#include<vector>
using namespace std;
int dp(int n,const vector<int> &coins ){
    if(n==0) return 0;
    if(n<0) return -1;
    int res = numeric_limits<int>::max();
    int subprob = 0;
    for(auto c:coins){
        subprob = dp(n-c,coins);
        if(subprob == -1) continue;
        res = min(res,subprob+1);
    }
    return res != numeric_limits<int>::max() ? res:-1;
}

int coinChange(int n,vector<int> &coins )
{
    cout<<"result "<<dp(n,coins);
}
int main()
{
    vector<int> coins{1,2,5};
    coinChange(1,coins);
    return 0;
}