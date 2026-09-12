// Last updated: 9/12/2026, 9:14:07 PM
1class Solution {
2public:
3    vector<int> nums;
4    int k;
5    long long solve(){
6        long long neg = INT_MIN;
7        long long ans = neg;
8        long long tmp1 = neg;
9        long long tmp2 = neg;
10        long long tmp3 = neg;
11
12        for(int i=0;i<nums.size();i++){
13            long long val = nums[i];
14            long long val2 = 1LL*nums[i]*k;
15           tmp3 = max({tmp2 + val , val ,tmp3+val});
16            tmp2 = max({tmp2+ val2 , tmp1+val2,val2});
17            tmp1=max({tmp1 +val , val});
18            ans = max({ans,tmp1,tmp2,tmp3});
19        }
20    return ans;
21    }
22    long long solve2(){
23        long long neg = INT_MIN;
24        long long ans = neg;
25        long long tmp1 = neg;
26        long long tmp2 = neg;
27        long long tmp3 = neg;
28
29        for(int i=0;i<nums.size();i++){
30            long long val = nums[i];
31            long long val2 = 1LL*(nums[i]/k);
32           tmp3 = max({tmp2 + val , val ,tmp3+val});
33            tmp2 = max({tmp2+ val2 , tmp1+val2,val2});
34            tmp1=max({tmp1 +val , val});
35            ans = max({ans,tmp1,tmp2,tmp3});
36        }
37    return ans;
38    }
39    long long maxSubarraySum(vector<int>& nums, int k) {
40        this->nums= nums;
41        this->k = k;
42        return max(solve() ,solve2());
43    }
44};