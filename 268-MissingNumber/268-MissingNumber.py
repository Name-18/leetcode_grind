# Last updated: 10/8/2026, 12:44:20 AM
1class Solution:
2    def missingNumber(self, nums: list[int]) -> int:
3        
4        n = len(nums)
5
6        sm = n*(n+1)
7        sm = sm//2
8
9        tot= 0
10
11        for i in range(0,len(nums)):
12            tot+=nums[i]
13
14        return sm - tot    