# Last updated: 10/8/2026, 10:57:30 AM
1class Solution:
2    def romanToInt(self, s: str) -> int:
3        num = 0
4        i = 1
5        while i <= len(s):
6          
7            if i<len(s) and s[i] == 'V' and s[i-1] =='I' :
8                num+=4
9                i+=2
10            elif  i<len(s) and s[i] == 'X' and s[i-1] =='I' :
11                num+=9
12                i+=2
13            elif i<len(s) and s[i] == 'L' and s[i-1] =='X' :  
14                num += 40
15                i+=2
16            elif i<len(s) and s[i] == 'C' and s[i-1] =='X' :  
17                num += 90
18                i+=2
19            elif i<len(s) and s[i] == 'D' and s[i-1] =='C' :  
20                num += 400
21                i+=2
22            elif i<len(s) and s[i] == 'M' and s[i-1] =='C' :  
23                num += 900
24                i+=2
25            elif  s[i-1] == 'I':   
26                num+=1
27                i+=1
28            elif  s[i-1] == 'V' :  
29                num+=5
30                i+=1
31            elif  s[i-1] == 'X' :  
32                num+=10
33                i+=1
34            elif  s[i-1] == 'L':   
35                num+=50
36                i+=1
37            elif  s[i-1] == 'C':   
38                num+=100
39                i+=1
40            elif  s[i-1] == 'D':   
41                num+=500
42                i+=1
43            elif  s[i-1] == 'M' :  
44                num+=1000
45                i+=1
46        return num     
47             