// Last updated: 6/21/2026, 8:23:18 AM
1class Solution {
2public:
3    int maxDistance(string moves) {
4   int x =0;
5        int y=0;
6        int cnt =0;
7        for(auto it:moves){
8            if(it=='L'){
9                x--;
10            }else if(it=='R'){
11                x++;
12            }else if(it=='U'){
13                y++;
14            }else if(it=='D'){
15                y--;
16            }else{
17                cnt++;
18            }
19        }
20        int ans = abs(x) + abs(y) + abs(cnt);
21
22        return ans;
23    }
24};