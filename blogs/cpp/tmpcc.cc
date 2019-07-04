#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
std::vector<int> mNumberList;
bool getResult(int& secondMaxNumber)
{
    if(mNumberList.empty()) {
        return false;
    }
    int firstmax = 0;
    int secondmax = 0;
    for_each(begin(mNumberList),end(mNumberList),[&](int n){
                 if(n>firstmax){
                     secondmax = firstmax;
                     firstmax = n;
                 }
                                                 });
             secondMaxNumber = secondmax;
             return true;
}
int main(){
    int result;
    mNumberList.push_back(0);
    mNumberList.push_back(1);
    mNumberList.push_back(2);
    mNumberList.push_back(3);
    getResult(result);
    cout<<result;

}
