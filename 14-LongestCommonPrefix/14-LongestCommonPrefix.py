# Last updated: 10/8/2026, 10:23:28 AM
1
2class Solution:
3    def longestCommonPrefix(self, strs: list[str]) -> str:
4        ln = 201
5        for i in range(len(strs)):
6              ln = min(ln , len(strs[i]))
7         
8        s = ""
9        for k in range(ln):
10            dic = {}
11            for j in range(len(strs)):
12                   
13                dic[strs[j][k]] = dic.get(strs[j][k],0)+1
14                
15            if len(dic) > 1:
16                break
17            else:
18                s+=strs[0][k]        
19        return s        
20          
21                
22                
23        
24        