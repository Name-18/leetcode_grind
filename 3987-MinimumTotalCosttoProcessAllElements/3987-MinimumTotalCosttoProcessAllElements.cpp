// Last updated: 7/12/2026, 6:04:31 PM
1class Solution {
2public:
3int mod = 1e9+7;
4    int func(int n){
5
6       long long x = 1LL*n*(n+1);
7       x/=2;
8       x%=mod;
9
10       return x ;
11    }
12    int minimumCost(vector<int>& nums, int k) {
13        
14        int n = nums.size();
15        int t = k;
16        int cnt = 0;
17        long long ans = 0;
18        for(int i=0;i<n;i++){
19               cout<<i<< " - >";
20               if(nums[i] <= k){
21                k-=nums[i];
22               }else{
23                    
24                    int cl = ((nums[i] - k) + t-1)/t ;
25              
26                    k = cl*t + k - nums[i];
27                   
28                    ans += (func(cnt + cl) - func(cnt));
29                    cnt +=cl;
30                    ans %=mod;
31                    cnt%=mod;
32               }
33        }
34
35        return ans;
36    }
37};