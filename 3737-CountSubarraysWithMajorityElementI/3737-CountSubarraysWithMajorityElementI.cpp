// Last updated: 6/26/2026, 12:44:18 AM
1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4      
5        int res = 0;
6        for(int i=0;i<nums.size();i++){
7            int cnt =0;
8            for(int j=i;j<nums.size();j++){
9               if(nums[j]==target){
10                   cnt+=1;
11                   
12               }
13                int len =j-i+1;
14               if(cnt>len/2){
15                    res+=1;
16                }
17                
18                }
19            }
20        
21    return res;
22}
23};