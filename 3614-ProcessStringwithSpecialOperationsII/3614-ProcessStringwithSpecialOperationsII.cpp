// Last updated: 6/18/2026, 3:08:28 AM
1class Solution {
2public:
3    char processStr(string s, long long k) {
4        int n = s.length();
5
6        long long L = 0;
7
8        for(char &ch : s) {
9            if(ch == '*') {
10                if(L > 0)
11                    L--;
12            } else if(ch == '#') {
13                L *= 2;
14            } else if(ch == '%') {
15             
16                continue;
17            } else { 
18                L++;
19            }
20        }
21
22        if(k >= L) {
23            return '.';
24        }
25
26        for(int i = n-1; i >= 0; i--) {
27            if(s[i] == '*') {
28                L++; 
29            } else if(s[i] == '%') {
30              
31                k = L - k - 1;
32            } else if(s[i] == '#') {
33                L = L/2;
34                k = (k >= L) ? k - L : k;
35            } else {
36                L--;
37            }
38
39            if(k == L) {
40                return s[i];
41            }
42        }
43
44        return '.';
45
46    }
47};
48
49