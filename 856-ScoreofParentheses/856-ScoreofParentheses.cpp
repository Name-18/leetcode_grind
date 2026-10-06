// Last updated: 10/7/2026, 12:42:30 AM
1class Solution {
2public:
3    int scoreOfParentheses(string s) {
4        vector<int> vec;
5int ans = 0;
6        int ct = 0;
7        bool fl = false;
8        for (int i = 0; i < s.size(); i++) {
9 
10            if (s[i] == ')') {
11           
12                ct -= 1;
13
14                if(fl){
15            
16                       ans += pow(2 , ct);
17                       fl = false;
18                }
19            } else {
20                ct += 1;
21                fl = true;
22
23            }
24            vec.push_back(ct);
25        }
26      
27        return ans;
28    }
29};