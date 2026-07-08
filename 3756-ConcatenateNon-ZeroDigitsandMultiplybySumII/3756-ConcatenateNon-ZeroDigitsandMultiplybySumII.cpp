// Last updated: 7/8/2026, 7:52:30 PM
1class Solution {
2public:
3const int mod= 1e9+7;
4    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
5         int n = s.size();
6        vector<long long > pref(n);
7        vector<long long> pref_s(n);
8        vector<int> dig(n);
9        vector<long long> power(n+1,1);
10
11        for(int i=1;i<=n;i++){
12            power[i] =  (power[i-1]*10)%mod;
13        }
14        long long summ =0;
15        long long numb =0;
16        int d =0;
17
18        for(int i=0;i<n;i++){
19
20            int num = s[i]-'0';
21            summ+= num;
22            summ %= mod;
23            if(num==0){
24            dig[i] = d;
25            pref[i] = numb;
26            pref_s[i]= summ;
27            }else{
28                  d+=1;
29
30                  numb*=10;
31                  numb %=mod;
32                  numb += num;
33                  numb %= mod;
34                     dig[i] = d;
35            pref[i] = numb;
36            pref_s[i]= summ;
37            }
38        }
39  vector<int> res;
40        for(auto it : queries){
41            int r = it[1];
42            int l = it[0];
43
44
45
46            if(l>0){
47                  
48                  int d = dig[r] - dig[l-1];
49                  long long a = (pref[r] - (1LL*(pref[l-1])*power[d])%mod + mod)% mod;
50                  a = (a  * ((pref_s[r] - pref_s[l-1] + mod)%mod)) % mod;
51        res.push_back(a);
52            }else{
53                    long long a = (1LL* pref[r] * pref_s[r]);
54                    a %= mod;
55                        res.push_back(a);
56            }
57        }
58        return res;
59    }
60};