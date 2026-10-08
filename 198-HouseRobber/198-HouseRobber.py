# Last updated: 10/8/2026, 11:41:26 PM
1class Solution:
2    def func(self ,idx , nums,dp):
3        if(idx >= len(nums)):
4            return 0
5        if dp[idx] != -1:
6            return dp[idx]    
7        
8        dp[idx] = max(nums[idx] + self.func(idx+2,nums,dp) , self.func(idx+1,nums,dp))
9        return dp[idx]
10    def rob(self, nums: list[int]) -> int:
11       dp = [-1]*(len(nums))
12       return (self.func(0,nums,dp))