// Last updated: 8/20/2026, 5:33:41 PM
1class Solution {
2public:
3    int destroyTargets(vector<int>& nums, int space) {
4        sort(nums.begin(),nums.end());
5        map<int,vector<int>> mpp;
6        for(auto &it:nums){
7            int rem = it%space;
8            mpp[rem].push_back(it);
9        }
10        int mx = 0;
11        set<int> st;
12        for(auto it : mpp){
13             mx = max(mx , (int)it.second.size());
14        }
15
16        for(auto it : mpp){
17
18            if(it.second.size() == mx){
19
20                st.insert(it.second[0]);
21            }
22        }
23        
24      return *st.begin();
25    }
26};