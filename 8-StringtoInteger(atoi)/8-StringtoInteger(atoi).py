# Last updated: 10/8/2026, 11:23:12 AM
1class Solution:
2    def myAtoi(self, s: str) -> int:
3        x = s.split()
4        st = s.lstrip()
5        pos = 1
6        num = 0
7        print(st)
8        if len(st) == 0:
9            return 0
10        if st[0].isdigit() :
11               num= num*10 + int(st[0])
12        else :
13            if st[0] == '+':
14                 pos =1
15            elif st[0]=='-':
16                 pos =0
17            else :
18                
19                return 0          
20        
21        for i in range(1,len(st)):
22
23            if st[i].isdigit():
24
25                num =num*10 +int(st[i])
26            else:
27                break
28        if pos ==0:
29            num*=-1
30        if num > (2**31)-1:
31            num = (2**31)-1 
32        elif num < -1*(2**31):
33            num = -1*(2**31)
34        return num    
35