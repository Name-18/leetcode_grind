// Last updated: 7/25/2026, 8:23:48 PM
1class Solution {
2public:
3    long long coloredCells(int n) {
4        long long ans  =  1LL*2*(n-1)*(n);
5        ans +=1;
6        return ans;
7    }
8};