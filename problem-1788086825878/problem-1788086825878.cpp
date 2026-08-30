// Last updated: 8/30/2026, 4:17:05 PM
1class Solution {
2public:
3    int mod = 1e9+7;
4   long long fast(long long x, long long y) {
5    if (y == 0) return 1;
6    
7    x %= mod; 
8    
9
10    long long half = fast(x, y / 2);
11    long long half_sq = (half * half) % mod;
12
13    if (y % 2 != 0) {
14        return (half_sq * x) % mod;
15    }
16    return half_sq;
17}
18
19    int sumDecoded(vector<long long>& nums) {
20long long ans = 0;
21        for(int i=0;i<nums.size();i++){
22            int w = nums[i]%10;
23            long long t = nums[i]/10;
24            string s = to_string(t);
25            long long x =0;
26            for(int k = 0 ;k<w;k++){
27                x*=10;
28                x+= s[k]-'0';
29            }
30           
31            long long  y = 0;
32            for(int k = w ;k<s.size();k++){
33                y*=10;
34                y+= s[k]-'0';
35            }
36
37            long long l = fast(x,y);
38            l%= mod;
39            ans += l;
40            ans %= mod;
41        }
42        return ans;
43    }
44};