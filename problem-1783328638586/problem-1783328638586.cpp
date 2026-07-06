// Last updated: 7/6/2026, 2:33:58 PM
1class Solution {
2public:
3    int maxValidPairSum(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<int> pref(n);
6        pref[n-1] = nums[n-1];
7        for(int i = n-2;i>=0;i--){
8            pref[i] = max(pref[i+1] , nums[i]);
9        }
10       
11        int ans =0;
12        for(int i=0;i<n;i++){
13
14            int j = i + k;
15
16            if(j<n){
17
18                 int tmp = nums[i] + pref[j];
19                ans = max(ans, tmp);
20            }
21        }
22        return ans;
23    }
24};