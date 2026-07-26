// Last updated: 7/26/2026, 1:28:36 PM
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        
5        map<int,int> mpp;
6        mpp[0]=1;
7        int n = nums.size();
8        int ans = 0;
9        int su = 0;
10        for(int i=0;i<n;i++){
11            su+= nums[i];
12            int req =  su -k; 
13            if(mpp.find(req) != mpp.end()){
14                   ans += mpp[req];
15            }
16
17            mpp[su]+=1;
18        }
19return ans;
20    }
21};