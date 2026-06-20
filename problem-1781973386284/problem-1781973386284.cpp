// Last updated: 6/20/2026, 10:06:26 PM
1class Solution {
2public:
3    long long dp[16][2][2][10];
4        vector<int> digit;
5   long long func(int idx, int str, int tight, int k, int prev) {
6        if (idx == digit.size()) {
7            return str; // Returns 1 if we formed a valid number, 0 if it was all zeros
8        }
9        
10        if (dp[idx][str][tight][prev] != -1) {
11            return dp[idx][str][tight][prev];
12        }
13
14        int lim = (tight) ? digit[idx] : 9;
15        long long ans = 0;
16
17        // Always start from 0 to allow numbers with fewer digits
18        for (int i = 0; i <= lim; i++) {
19            int n_tight = (tight) && (i == lim);
20
21            if (!str) {
22                if (i == 0) {
23                    // Still a leading zero; 'str' remains 0, 'prev' doesn't matter (pass 0)
24                    ans += func(idx + 1, 0, n_tight, k, 0);
25                } else {
26                    // Number starts here!
27                    ans += func(idx + 1, 1, n_tight, k, i);
28                }
29            } else {
30               
31                if (abs(prev - i) <= k) {
32                    ans += func(idx + 1, 1, n_tight, k, i);
33                }
34            }
35        }
36
37        if (!tight) {
38            dp[idx][str][tight][prev] = ans;
39        }
40
41        return ans;
42    }
43    long long solve(long long n , int k){
44        this->digit.clear();
45         memset(dp,-1,sizeof(dp));
46        string s = to_string(n);
47
48        for(auto it:s){
49              this->digit.push_back(it-'0');
50        }
51        return func(0,0,1,k,0);
52    }
53    int check(long long x,int k){
54        memset(dp,-1,sizeof(dp));
55        vector<int> d;
56        string s = to_string(x);
57        for(auto it:s){
58            d.push_back(it-'0');
59        }
60        int ans =1;
61
62        for(int i=1;i<d.size();i++){
63            if(abs(d[i]-d[i-1])>k){
64                ans = 0;
65                return 0;
66            }
67        }
68        return 1;
69    }
70    long long goodIntegers(long long l, long long r, int k) {
71        
72        return  solve(r,k) - solve(l,k) + check(l,k);
73    }
74};