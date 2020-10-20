#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto size1=nums1.size();
    auto size2=nums2.size();
    vector<int> output;
    vector<int>::iterator itnums1;
    vector<int>::iterator itnums2;
    itnums1=nums1.begin();
    itnums2=nums2.begin();
    //cout<<"itnums:"<<*itnums1<<endl;
    while(true){
      if(itnums1 != nums1.end()){
        if(itnums2 != nums2.end()){
          if(*itnums1 < *itnums2){
            output.push_back(*itnums1);
            ++itnums1;
          }else{
            output.push_back(*itnums2);
            ++itnums2;
          }
        }else{
          output.push_back(*itnums1);
          ++itnums1;
        }
      }else{
        if(itnums2 != nums2.end()){
          output.push_back(*itnums2);
          ++itnums2;
        }else{
          break;
        }

      }
    }//end while
    for(auto v:output){
      cout<<v<<"\t";
    }
    cout<<endl;
    auto len = output.size();
    if (len % 2==1){
      return output[int(len/2)];
    }
    auto middle = len / 2;
    return (output[middle-1]+output[middle])/2.f;

  }
};
int main(){
  vector<int> v1={1,2};
  vector<int> v2={3,4};

  Solution s;
  double median=s.findMedianSortedArrays(v1, v2);
  cout<<"mdian value: "<<median<<endl;
}
