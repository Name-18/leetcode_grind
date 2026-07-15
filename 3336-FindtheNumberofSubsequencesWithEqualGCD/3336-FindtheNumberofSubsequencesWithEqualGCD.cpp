// Last updated: 7/15/2026, 3:34:42 PM
1class Solution {
2public:
3  vector<int> nums;
4  int dp[201][202][202];
5  int mod = 1e9+7;
6    int func(int idx , int seq1 , int seq2){
7          
8          if(idx == nums.size()){
9            return seq1 == seq2 and seq1 != -1; 
10          }
11         
12         if(dp[idx][seq1+1][seq2+1] != -1) return dp[idx][seq1+1][seq2+1];
13        long long nt = func(idx+1,seq1,seq2);
14        long long take1 = 0;
15        int t = seq1;
16        int t2 = seq2;
17        if(seq1 == -1){
18            seq1 = nums[idx];
19        }else{
20            seq1 = __gcd(seq1,nums[idx]);
21        }
22         take1 =  func(idx+1,seq1 ,seq2);
23         
24        long long take2 =0 ;
25
26        if(seq2 == -1){
27            seq2 = nums[idx];
28        }
29        else{
30            seq2 = __gcd(seq2,nums[idx]);
31        }
32
33        take2 = func(idx+1 , t ,seq2);
34        long long ans =  nt+take1+take2;
35        ans %= mod;
36        return  dp[idx][t+1][t2+1] = ans;
37    }
38    int subsequencePairCount(vector<int>& nums) {
39        this->nums = nums;
40       memset(dp,-1,sizeof(dp));
41        return func(0,-1,-1);
42    }
43};