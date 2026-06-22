// Last updated: 6/22/2026, 4:44:17 PM
1class Solution {
2public:
3    using ll = long long;
4    int waysToSplitArray(vector<int>& nums) {
5        vector<ll> pref(nums.size(),0);
6        pref[0]= nums[0];
7
8        for(int i = 1;i<nums.size();i++)  pref[i] += (pref[i-1] + nums[i]);
9
10        ll tot = pref[nums.size()-1];
11        ll ans =0;
12        for(int i=0;i<nums.size()-1;i++){
13
14            if(pref[i] >=  tot - pref[i]) ans += 1;
15        }
16        return ans;
17    }
18};