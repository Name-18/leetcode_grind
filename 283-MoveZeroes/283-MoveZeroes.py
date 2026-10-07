# Last updated: 10/8/2026, 12:26:27 AM
1class Solution:
2    def moveZeroes(self, nums: list[int]) -> None:
3        """
4        Do not return anything, modify nums in-place instead.
5        """
6        arr = nums
7        cnt = 0 
8        for i in range(0,len(nums)):
9            if nums[i] == 0:
10                cnt+=1
11        j =0
12        for i in range( 0 ,len(nums)):
13              
14              if(nums[i] != 0):
15                 arr[j] = nums[i]
16                 j+=1  
17
18        for i in range(j,len(nums)):
19            arr[i] = 0         
20
21        nums= arr.copy()    