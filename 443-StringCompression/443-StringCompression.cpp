// Last updated: 9/3/2026, 12:20:08 AM
1class Solution {
2public:
3    int compress(vector<char>& chars) {
4        
5        int ans = 0;
6        int cnt = 1;
7        int n = chars.size()-1;
8        string op = "";
9        for(int i= 1;i<chars.size();i++){
10
11            if(chars[i]  == chars[i-1]){
12                cnt+=1;
13            }else{
14
15                if(cnt ==1){
16                    ans += 1;
17                    op+=chars[i-1];
18                }else{
19                 
20                 string s = to_string(cnt);
21                    op+=chars[i-1];
22                    op += s;
23                 ans += s.size()+1;
24                 cnt = 1;
25                }
26            }
27        }
28         if(cnt ==1){
29                    ans += 1;
30                         op+=chars[n];
31                }else{
32                 
33                 string s = to_string(cnt);
34                  op+=chars[n];
35                    op += s;
36                 ans += s.size()+1;
37                 cnt = 1;
38                }
39           for(int i=0;i<op.size();i++){
40            chars[i] = op[i];
41           }
42                return ans;
43    }
44};