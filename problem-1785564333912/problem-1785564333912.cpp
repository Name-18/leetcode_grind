// Last updated: 8/1/2026, 11:35:33 AM
1class Solution {
2public:
3    int minOperations(int k) {
4
5        int ans = k-1;
6        for(int i=0;i<=k;i++){
7
8            int x = (k + i)/(1+i);
9            x--;
10
11            ans = min(ans , x+i);
12            
13        }
14        return ans;
15    }
16};