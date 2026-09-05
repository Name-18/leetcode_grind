// Last updated: 9/5/2026, 12:29:10 PM
1class Solution {
2public:
3    int sumOfGoodIntegers(int n, int k) {
4
5
6         int t = n + k;
7        int sim=0;
8        for(int i= 0;i<=n+k;i++){
9                
10            if((i & n) == 0 and abs(n - i)<= k){
11             
12                sim+=i;
13            }
14        }
15        return sim;
16    }
17};