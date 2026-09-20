// Last updated: 9/20/2026, 12:30:25 PM
1class Solution {
2public:
3    int reverseDegree(string s) {
4        int sm = 0;
5        int idx=1;
6        for(auto & ch : s){
7
8            int rev =  26 - (ch - 'a') ;
9            
10           
11            sm  += rev * idx;
12            idx+=1;
13        }
14        return sm;
15    }
16};