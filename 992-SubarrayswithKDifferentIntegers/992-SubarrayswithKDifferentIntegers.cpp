// Last updated: 6/18/2026, 2:39:55 PM
1class Solution {
2public:
3  int func(vector<int>& nums, int k){
4             
5             map<int,int> mpp;
6             int cnt =0 ;
7             int l =0;
8             for(int r =0;r<nums.size();r++){
9                mpp[nums[r]]+=1;
10
11                if(mpp.size()>k){
12                    while(mpp.size()!=k){
13                        mpp[nums[l]]--;
14                        if(mpp[nums[l]]==0){
15                            mpp.erase(nums[l]);
16                        }
17                        l++;
18                    }
19                }
20                cnt += r-l+1;
21             }
22             return cnt;
23  }
24    int subarraysWithKDistinct(vector<int>& nums, int k) {
25       return func(nums,k)-func(nums,k-1);
26    }
27};