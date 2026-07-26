// Last updated: 7/26/2026, 1:38:54 PM
1class Solution {
2public:
3    int maxScore(string s) {
4
5        int cnt  = 0;
6        for(auto &it : s){
7            if(it == '1') cnt +=1;
8        }
9         int cnt1 =0 ;
10        int res = 0;
11        for(int i=0;i<s.size()-1;i++){
12           if(s[i]=='0'){
13               cnt1+=1;
14           }else{
15               cnt --;
16           }
17            res = max(res ,  cnt + cnt1);
18        }
19        return res;
20    }
21};