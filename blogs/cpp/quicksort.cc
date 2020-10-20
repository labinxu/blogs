#include <iostream>
#include <vector>
using namespace std;
void quicksort(vector<int> &vints,int begin,int end){
    if(begin>end)return;
    int low = begin;
    int high = end;
    int key = vints[low];
    int tmp=0;
    while(low<high){
        while(low<high && vints[low]<key) low++;
        while(low<high && vints[high]>key) high--;
        tmp = vints[low];
        vints[low]=vints[high];
        vints[high] = tmp;
        for(auto v:vints){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    
    quicksort(vints, begin, low-1);
    quicksort(vints, low+1, end);
}

void quicksort2(vector<int> &vints,int begin, int end){
    if(begin>end) return;
    int low = begin;
    int high = end;
    int key = vints[low];
    while(low<end){
        while(low<end && vints[high]>=key) --high;
        vints[low]=vints[high];
        vints[high]=key;
        while(low<end && vints[low]<=key) --low;
        vints[high]=vints[low];
        vints[low]=key;
    }
    for(auto v:vints){
        cout<<v<<" ";
    }

    cout<<endl;
    quicksort2(vints, begin, low-1);
    quicksort2(vints, low+1, end);
}
int main(){
    vector<int> vints={2,1,4,3};
    quicksort2(vints, 0, vints.size()-1);
}
