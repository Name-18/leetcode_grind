# Last updated: 10/8/2026, 10:41:56 AM
1class Solution:
2    def firstUniqChar(self, s: str) -> int:
3        
4        dict = {}
5
6        for i in range(len(s)):
7
8            dict[s[i]] = dict.get(s[i],0)+1
9
10        for i in range(len(s)):
11
12            if dict[s[i]]==1 :
13                return i   
14        return -1        