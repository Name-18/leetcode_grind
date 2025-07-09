#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
     
    //  map<int,int> mpp;
    //  for(auto it: nums){
    //     mpp[it]++;
    //     if(mpp[it]>=2) return true;
    //  }
    //  return false;
 int ans;
    for(auto it : nums){
ans = ans ^ it;
    }
    return ans==1;
     }


};