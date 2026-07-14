// Last updated: 7/14/2026, 4:10:31 PM
1class Solution {
2public:
3    int maxSubarraySumCircular(vector<int>& nums) {
4        int tot =accumulate(nums.begin(),nums.end(),0);
5
6        int mx = nums[0];
7        int mi =nums[0];
8        int bestmi=nums[0];
9        int bestmx =nums[0];
10        for(int i=1;i<nums.size() ; i++){
11            int t1 = mx ;
12            int t2 = mi ;
13            
14            mx = max({t1+nums[i] , nums[i] , t2 + nums[i]});
15            mi = min({t1+nums[i] , nums[i] , t2 + nums[i]});
16            bestmi = min(bestmi , mi);
17            bestmx= max(bestmx , mx);
18        }
19
20        int ans  = bestmx;
21        if(tot - bestmi !=0){
22            ans = max(ans,tot - bestmi);
23        }
24        return ans;
25    }
26};