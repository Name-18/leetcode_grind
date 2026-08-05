// Last updated: 8/5/2026, 12:50:52 PM
1class Solution {
2public:
3    int minFlipsMonoIncr(string s) {
4int cnt = 0;
5        for(auto &it : s){
6            if(it == '0'){
7                cnt++;
8            }
9        }
10 int cnt_0=0;
11        int cnt_1 =0;
12        int mi =  cnt;
13        for(int i=0;i<s.size();i++){
14            int flip = 0;
15            if(s[i] == '0'){
16                 cnt_0+=1;
17
18            }else{
19                cnt_1+=1;
20                
21            }
22            flip += cnt -cnt_0;
23            flip += cnt_1;
24            mi = min(mi,flip);
25        }
26        return mi;
27    }
28};