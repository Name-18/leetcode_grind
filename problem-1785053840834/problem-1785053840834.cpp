// Last updated: 7/26/2026, 1:47:20 PM
1class Solution {
2public:
3    int maxScore(vector<int>& nums, int k) {
4         
5        k = nums.size()  -  k ;
6        // if(k==0){
7        //          int ans =  accumulate(nums.begin() ,  nums.end() , 0);
8        //     return ans;
9        // }
10        int su = 0;
11        int res = 0;
12        for(int i=0;i<k;i++){
13            su+=nums[i];
14            
15        }
16        res =  su;
17        int l = 0;
18        for(int i=k;i<nums.size();i++){
19            su-=nums[l];
20            su += nums[i];
21            l++;
22            res = min(res,su);
23        }
24        int ans =  accumulate(nums.begin() ,  nums.end() , 0);
25        ans -= res;
26        return ans;
27    }
28};