// Last updated: 7/12/2026, 2:29:12 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        
5
6        long long x = accumulate( nums.begin() , nums.end(),0);
7
8        vector<long long> pref(nums.size(),0);
9
10        for(int i=0;i<nums.size(); i++){
11            pref[i] =  x -  nums[i];
12            
13        }
14        long long curr = 0;
15
16        for(int i=0;i<nums.size();i++){
17         curr += nums[i]*i;
18
19        }
20
21        long long ans = 0;
22        ans = curr;
23
24
25
26        for(int i=0;i<nums.size();i++){
27        long long tmp = curr - pref[i];
28        tmp += nums[i]*(nums.size()-1);
29    
30        curr = tmp;
31    
32        ans = max(ans,tmp);
33        }
34        return ans;
35    }
36};