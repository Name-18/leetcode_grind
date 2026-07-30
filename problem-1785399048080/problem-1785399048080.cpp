// Last updated: 7/30/2026, 1:40:48 PM
1class Solution {
2public:
3    long long mod = 1e9+7;
4    int fact(int n){
5
6        long long x = 1;
7        for(int i=1;i<=n;i++){
8
9            x *= i;
10
11            if(x >= mod){
12                x %= mod;
13            }
14        }
15        x%=mod;
16        return x;
17    }
18    int countPermutations(vector<int>& complexity) {
19        int n = complexity.size();
20        n-=1;
21        int mn = *min_element(begin(complexity),end(complexity));
22        int cnt = 0;
23        if(complexity[0] != mn) return 0;
24        for(auto &it  : complexity){
25            if(it == mn) cnt+=1;
26        }
27        if(cnt > 1) return 0;
28        
29        return fact(n);
30    }
31};