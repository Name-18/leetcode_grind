// Last updated: 7/14/2026, 12:41:55 PM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        
5        int n =  nums.size();
6        vector<int> pref1(n);
7        vector<int> pref2(n);
8        int mul = 1;
9        for(int i=0 ;i<n;i++){
10                 mul*=nums[i];
11                 pref1[i] = mul;
12        }
13        mul =1;
14          for(int i=n-1 ;i>=0;i--){
15                 mul*=nums[i];
16                 pref2[i] = mul;
17        }
18
19        vector<int> res(n);
20        for(int i=0;i<n;i++){
21
22            if(i==0){
23               res[i] =  pref2[1];
24            }else if(i==n-1){
25                res[i] = pref1[n-2];
26            }
27            else {
28                res[i] = pref1[i-1] * pref2[i+1];
29            }
30        }
31
32        return res;
33    }
34};