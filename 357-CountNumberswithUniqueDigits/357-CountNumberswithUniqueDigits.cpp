// Last updated: 7/7/2026, 6:07:34 PM
1class Solution {
2public:
3     string s;
4     int dp[10][2][2][1024];
5     int func(int idx , int str ,int lim, int bit){
6               if(idx >=  s.size()){
7                return 1;
8               }
9           int l =  10;
10           if(lim) l =  s[idx]-'0' +1;
11
12           if(dp[idx][str][lim][bit] !=-1 and lim == 1) return dp[idx][str][lim][bit];
13           int ans =0;
14           for(int i=0;i<l;i++){
15              int n_lim = lim && (s[idx]- '0' == i);
16    
17              if(!str){
18                if(i==0){
19             ans +=  func(idx +1 , 0 , n_lim ,bit);
20                }else{
21                    ans +=  func(idx +1 , 1 , n_lim ,bit | (1<<i));
22                }
23              }else{
24                
25                if((bit & (1 << i)) == 0){
26                      ans +=  func(idx +1 , 1 , n_lim ,bit | (1<<i));
27                }
28
29              }
30           }
31           if(lim != 0) dp[idx][str][lim][bit]=ans;
32           return ans;
33     }
34    int countNumbersWithUniqueDigits(int n) {
35        n = pow(10,n);
36        n-=1;
37        this->s = to_string(n);
38        memset(dp,-1,sizeof(dp));
39        return func(0, 0,1,0);
40    }
41};