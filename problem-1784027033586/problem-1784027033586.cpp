// Last updated: 7/14/2026, 4:33:53 PM
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        map<int,int>  mpp;
5        int su = 0;
6        int cnt = 0;
7        mpp[0]=1;
8        for(int i=0;i<nums.size() ; i++){
9                su += nums[i];
10
11                if(mpp.find(su-k) != mpp.end()){
12                       cnt += mpp[su-k];
13                }
14                mpp[su] +=1;
15        }
16
17    
18        return cnt;
19    }
20};