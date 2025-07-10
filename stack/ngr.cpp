#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>> st;
   vector<int> ans;
      for(int i= nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top().first<=nums[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(0);
        }else{
            int res = st.top().second-i;
            ans.push_back(res);
        }
        auto pp =make_pair(nums[i],i);
        st.push(pp);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};