// Last updated: 9/6/2026, 11:02:49 PM
1class Solution {
2public:
3    vector<int> locations;
4    int mod =  1e9+7;
5    int dp[201][101];
6    int func(int fuel, int loc, int finis) {
7        if(fuel == 0){
8            return finis==loc;
9        }
10         
11         if(dp[fuel][loc] != -1) return dp[fuel][loc];
12        long long ans = 0;
13         
14       
15        for (int i = 0; i < locations.size(); i++) {
16
17            if (i == loc)
18                continue;
19            int t = abs(locations[i] - locations[loc]);
20            if (t < fuel) {
21               
22                if(i == finis){
23                    ans += 1 + func(fuel - t , i , finis);
24                    ans %= mod;
25                }else{
26                    ans += func(fuel-t,i,finis);
27                      ans %= mod;
28                }
29            }
30            else if(t == fuel){
31                     ans += func(fuel-t,i,finis);
32                       ans %= mod;
33            }
34        }
35        return dp[fuel][loc] = ans;
36    }
37    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
38          this->locations = locations;
39          memset(dp,-1,sizeof(dp));
40        return func(fuel , start , finish) + (start == finish);
41    }
42};