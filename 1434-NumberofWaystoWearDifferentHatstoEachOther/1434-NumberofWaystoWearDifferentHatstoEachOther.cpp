// Last updated: 7/17/2026, 5:51:49 PM
1class Solution {
2public:
3    vector<int> nums;
4    int dp[502][26][502];
5    int func(int i ,int k , int last){
6
7                
8                 if(k==-1) {
9                   
10                    return -1;}
11                if(nums.size()==i){
12                  return 0;
13
14                    
15                }
16      if(dp[i][k][last+1]!=-1) return dp[i][k][last+1];
17                
18    int nt = func(i+1,k,last);
19
20    int take = 0;
21
22    if(last == -1){
23        take =1 + func(i+1,k,i); 
24    }else{
25        int t=  (nums[i] == nums[last]);
26        t = t-1;
27        take = 1 + func(i+1,k+t,i);
28    }
29        
30        return dp[i][k][last+1] = max(take,nt);
31    }
32    int maximumLength(vector<int>& nums, int k) {
33        this->nums = nums;
34        memset(dp,-1,sizeof(dp));
35       return func(0,k,-1);
36    }
37};