// Last updated: 8/6/2026, 12:22:10 PM
1class Solution {
2public:
3    long long maxPairStrength(vector<int>& nums) {
4        long long ans = 0;
5        for(int i=0;i<nums.size()-1;i++){
6            for(int j=i+1;j<nums.size();j++){
7
8                long long t = 1LL*nums[i]*nums[j];
9
10                long long k= (__gcd(nums[i],nums[j]));
11                k*=k;
12                t = t/k;
13                ans = max(ans,t);
14                
15            }
16        }
17        return ans;
18    }
19};