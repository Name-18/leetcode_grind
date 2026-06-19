// Last updated: 6/19/2026, 6:33:04 PM
1class Solution {
2public:
3  long long dp[100001][2];
4   long long func(int idx , int sign,vector<int>& nums){
5          if(idx == nums.size()){
6            return 0;
7          }
8        if(dp[idx][sign]!=INT_MIN) return dp[idx][sign];
9          long long ans =0;
10          if(sign){
11            ans = max(nums[idx] + func(idx+1,1,nums), nums[idx]*-1 + func(idx+1,0,nums));
12            return dp[idx][sign]= ans;
13          }
14          
15   
16          return dp[idx][sign]= nums[idx] + func(idx+1,1,nums);
17   }
18    long long maximumTotalCost(vector<int>& nums) {
19        for (int i = 0; i <= nums.size(); i++) {
20            dp[i][0] = INT_MIN;
21            dp[i][1] = INT_MIN;
22        }
23        return func(0,0,nums);
24    }
25};