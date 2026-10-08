# Last updated: 10/8/2026, 10:34:15 AM
1class Solution:
2    def reverseString(self, s: list[str]) -> None:
3        """
4        Do not return anything, modify s in-place instead.
5        """
6        
7        s[::] = s[::-1]
8    
9
10
11
12        